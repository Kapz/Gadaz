#include "shader.h"
#include "engine.h"

Shader *shader_create(const char *vertexShaderPath, const char *fragmentShaderPath){
    GLint status;
    Shader *shader = (Shader *)malloc(sizeof(Shader));
    if(shader == NULL){
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

    shader->vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader->vertexShader, 1, &vertexShaderData, (GLint *)&vertexShaderSize);
    glCompileShader(shader->vertexShader);
    
    glGetShaderiv(shader->vertexShader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE){
        GLint logSize;
        glGetShaderiv(shader->vertexShader, GL_INFO_LOG_LENGTH, &logSize);
        char *log = (char *)malloc(logSize);
        glGetShaderInfoLog(shader->vertexShader, logSize, NULL, log);
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

    shader->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader->fragmentShader, 1, &fragmentShaderData, (GLint *)&fragmentShaderSize);
    glCompileShader(shader->fragmentShader);
    
    glGetShaderiv(shader->fragmentShader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE){
        GLint logSize;
        glGetShaderiv(shader->fragmentShader, GL_INFO_LOG_LENGTH, &logSize);
        char *log = (char *)malloc(logSize);
        glGetShaderInfoLog(shader->fragmentShader, logSize, NULL, log);
        engine_logs("Failed to compile fragment shader: \n");
        engine_logs(log);
        free(log);
        return NULL;
    }

    if(create_shader_program(shader)){
        return NULL;
    }

    return shader;
}

Shader *shader_create_s(const GLchar *vertexShaderData, const GLchar *fragmentShaderData){
    GLint status;
    Shader *shader = (Shader *)malloc(sizeof(Shader));
    if(shader == NULL){
        engine_logs("Failed to allocate memory for shader object\n");
        return NULL;
    }

    shader->vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader->vertexShader, 1, &vertexShaderData, NULL);
    glCompileShader(shader->vertexShader);
    
    glGetShaderiv(shader->vertexShader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE){
        GLint logSize;
        glGetShaderiv(shader->vertexShader, GL_INFO_LOG_LENGTH, &logSize);
        char *log = (char *)malloc(logSize);
        glGetShaderInfoLog(shader->vertexShader, logSize, NULL, log);
        engine_logs("Failed to compile vertex shader: \n");
        engine_logs(log);
        free(log);
        return NULL;
    }

    shader->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader->fragmentShader, 1, &fragmentShaderData, NULL);
    glCompileShader(shader->fragmentShader);
    
    glGetShaderiv(shader->fragmentShader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE){
        GLint logSize;
        glGetShaderiv(shader->fragmentShader, GL_INFO_LOG_LENGTH, &logSize);
        char *log = (char *)malloc(logSize);
        glGetShaderInfoLog(shader->fragmentShader, logSize, NULL, log);
        engine_logs("Failed to compile fragment shader: \n");
        engine_logs(log);
        free(log);
        return NULL;
    }

    if(create_shader_program(shader)){
        return NULL;
    }

    return shader;
}

void shader_free(Shader *shader){
    glDeleteShader(shader->vertexShader);
    glDeleteShader(shader->fragmentShader);
    free(shader);
}

void shader_bind(Shader *shader){
    glUseProgram(shader->program);
}

GLuint shader_get_attrib_loc(Shader *shader, const char *name){
    return glGetAttribLocation(shader->program, name);
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

static GLint create_shader_program(Shader *shader){
    GLint status;

    shader->program = glCreateProgram();
    glAttachShader(shader->program, shader->vertexShader);
    glAttachShader(shader->program, shader->fragmentShader);
    glLinkProgram(shader->program);

    glGetProgramiv(shader->program, GL_LINK_STATUS, &status);
    if(status == GL_FALSE){
        GLint logSize;
        glGetProgramiv(shader->program, GL_PROGRAM_LENGTH_NV, &logSize);
        char *log = (char *)malloc(logSize);
        glGetProgramInfoLog(shader->program, logSize, NULL, log);
        engine_logs("Failed to create shader program: ");
        engine_logs(log);
        free(log);
        return 1;
    }
    
    return 0;
}