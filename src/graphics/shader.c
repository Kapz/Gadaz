#include "shader.h"
#include "../engine.h"

Shader *shader_create(const char *vertexShaderPath, const char *fragmentShaderPath){
    GLint status;
    Shader *s = (Shader *)malloc(sizeof(Shader));
    if(s == NULL){
        engine_logs("Failed to allocate memory for shader object\n");
        return NULL;
    }

    int vertexShaderSize = get_file_size(vertexShaderPath);
    if(vertexShaderSize == -1){
        engine_logs("Failed to obtain vertex shader size\n");
        return NULL;
    }

    GLchar *vertexShaderData = (GLchar *)malloc(vertexShaderSize);
    if(vertexShaderData == NULL){
        engine_logs("Failed to allocate memory for vertex shader\n");
        return NULL;
    }

    if(load_shader_source(vertexShaderPath, &vertexShaderData) == -1){
        engine_logs("Failed to read vertex shader file\n");
        free(vertexShaderData);
        return NULL;
    }

    s->vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(s->vertexShader, 1, &vertexShaderData, (GLint *)&vertexShaderSize);
    glCompileShader(s->vertexShader);
    
    glGetShaderiv(s->vertexShader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE){
        GLint logSize;
        glGetShaderiv(s->vertexShader, GL_INFO_LOG_LENGTH, &logSize);
        char *log = (char *)malloc(logSize);
        glGetShaderInfoLog(s->vertexShader, logSize, NULL, log);
        engine_logs("Failed to compile vertex shader: \n");
        engine_logs(log);
        free(log);
        return NULL;
    }

    /* We dont need the source after we compiled the shader*/
    free(vertexShaderData);

    int fragmentShaderSize = get_file_size(fragmentShaderPath);
    if(fragmentShaderSize == -1){
        engine_logs("Failed to obtain fragment shader size\n");
        return NULL;
    }

    GLchar *fragmentShaderData = (GLchar *)malloc(fragmentShaderSize);
    if(fragmentShaderData == NULL){
        engine_logs("Failed to allocate memory for fragment shader\n");
        return NULL;
    }

    if(load_shader_source(fragmentShaderPath, &fragmentShaderData) == -1){
        engine_logs("Failed to read fragment shader file\n");
        free(fragmentShaderData);
        return NULL;
    }

    s->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(s->fragmentShader, 1, &fragmentShaderData, (GLint *)&fragmentShaderSize);
    glCompileShader(s->fragmentShader);
    
    glGetShaderiv(s->fragmentShader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE){
        GLint logSize;
        glGetShaderiv(s->fragmentShader, GL_INFO_LOG_LENGTH, &logSize);
        char *log = (char *)malloc(logSize);
        glGetShaderInfoLog(s->fragmentShader, logSize, NULL, log);
        engine_logs("Failed to compile fragment shader: \n");
        engine_logs(log);
        free(log);
        return NULL;
    }

    if(create_shader_program(s)){
        return NULL;
    }

    return s;
}

Shader *shader_create_s(const GLchar *vertexShaderData, const GLchar *fragmentShaderData){
    GLint status;
    Shader *s = (Shader *)malloc(sizeof(Shader));
    if(s == NULL){
        engine_logs("Failed to allocate memory for shader object\n");
        return NULL;
    }

    s->vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(s->vertexShader, 1, &vertexShaderData, NULL);
    glCompileShader(s->vertexShader);
    
    glGetShaderiv(s->vertexShader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE){
        GLint logSize;
        glGetShaderiv(s->vertexShader, GL_INFO_LOG_LENGTH, &logSize);
        char *log = (char *)malloc(logSize);
        glGetShaderInfoLog(s->vertexShader, logSize, NULL, log);
        engine_logs("Failed to compile vertex shader: \n");
        engine_logs(log);
        free(log);
        return NULL;
    }

    s->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(s->fragmentShader, 1, &fragmentShaderData, NULL);
    glCompileShader(s->fragmentShader);
    
    glGetShaderiv(s->fragmentShader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE){
        GLint logSize;
        glGetShaderiv(s->fragmentShader, GL_INFO_LOG_LENGTH, &logSize);
        char *log = (char *)malloc(logSize);
        glGetShaderInfoLog(s->fragmentShader, logSize, NULL, log);
        engine_logs("Failed to compile fragment shader: \n");
        engine_logs(log);
        free(log);
        return NULL;
    }

    if(create_shader_program(s)){
        return NULL;
    }

    return s;
}

void shader_free(Shader *s){
    glDeleteShader(s->vertexShader);
    glDeleteShader(s->fragmentShader);
    free(s);
}

void shader_bind(Shader *s){
    glUseProgram(s->program);
}

GLuint shader_get_attrib_loc(Shader *s, const char *name){
    return glGetAttribLocation(s->program, name);
}

void shader_set_uniform_3f(Shader *s, const char *attrib, float p1, float p2, float p3){
    GLint uniLoc = glGetUniformLocation(s->program, attrib);
    glUniform3f(uniLoc, p1, p2, p3);
}

void shader_set_uniform_vec3(Shader *s, const char *attrib, Vec3 p1){
    GLint uniLoc = glGetUniformLocation(s->program, attrib);
    //TODO: Optimize this? All elements at once?
    glUniform3f(uniLoc, p1.x, p1.y, p1.z);
}

void shader_set_uniform_2f(Shader *s, const char *attrib, float p1, float p2){
    GLint uniLoc = glGetUniformLocation(s->program, attrib);
    glUniform2f(uniLoc, p1, p2);
}

void shader_set_uniform_1i(Shader *s, const char *attrib, int p1){
    GLint uniLoc = glGetUniformLocation(s->program, attrib);
    glUniform1i(uniLoc, p1);
}

void shader_set_uniform_1f(Shader *s, const char *attrib, float p1){
    GLint uniLoc = glGetUniformLocation(s->program, attrib);
    glUniform1f(uniLoc, p1);
}

void shader_set_uniform_mat4(Shader *s, const char *attrib, Mat4 p1){
    //TODO: Check this please ?
    GLint uniLoc = glGetUniformLocation(s->program, attrib);
    glUniformMatrix4fv(uniLoc, 1, GL_FALSE, (GLfloat *)&p1);
}


static int load_shader_source(const char* filepath, char **buffer){
    long shaderSourceSize = get_file_size(filepath);
    if(shaderSourceSize == -1){
        engine_logs("Failed to get shader source file size\n");
        return -1;
    }

    *buffer = (char *)malloc(shaderSourceSize);
    if(buffer == NULL){
        engine_logs("Failed to allocate memory for shader source\n");
        return -1;
    }

    FILE *fp = fopen(filepath, "r+");
    if(fp == NULL){
        engine_logs("Failed to read shader source file");
        return -1;
    }

    size_t read = fread(*buffer, 1, shaderSourceSize, fp);
    if(read < shaderSourceSize){
        engine_logs("Failed to read shader source file");
        return -1;
    }

    return shaderSourceSize;
}

static long get_file_size(const char *filepath){
    /* TODO: Look for better std-c alternative*/
    long fileSize;
    FILE *fp = fopen(filepath, "r+");
    if(fp == NULL){
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fclose(fp);

    return fileSize;
}

static GLint create_shader_program(Shader *s){
    GLint status;

    s->program = glCreateProgram();
    glAttachShader(s->program, s->vertexShader);
    glAttachShader(s->program, s->fragmentShader);
    glLinkProgram(s->program);

    glGetProgramiv(s->program, GL_LINK_STATUS, &status);
    if(status == GL_FALSE){
        GLint logSize;
        glGetProgramiv(s->program, GL_PROGRAM_LENGTH_NV, &logSize);
        char *log = (char *)malloc(logSize);
        glGetProgramInfoLog(s->program, logSize, NULL, log);
        engine_logs("Failed to create shader program: ");
        engine_logs(log);
        free(log);
        return 1;
    }
    
    return 0;
}