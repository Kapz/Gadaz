#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <stdlib.h>

typedef struct Shader{
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint program;
}Shader;

Shader *shader_create(const char *vertexShaderPath, const char *fragmentShaderPath);
Shader *shader_create_s(const GLchar *vertexShaderData, const GLchar *fragmentShaderData);
void shader_free(Shader *s);
void shader_bind(Shader *s);

GLuint shader_get_attrib_loc(Shader *s, const char *name);

/* File IO helper functions */
static int load_shader_source(const char *filepath, char **bufferPointer);
static long get_file_size(const char *filepath);
static GLint create_shader_program(Shader *s);

#endif