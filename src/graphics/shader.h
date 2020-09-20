#ifndef SHADER_H
#define SHADER_H

#include "../math/vector.h"
#include "../math/matrix.h"
#include <GL/glew.h>
#include <stdlib.h>

typedef struct{
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint program;
}Shader;

Shader *shader_create(const char *vertexShaderPath, const char *fragmentShaderPath);
Shader *shader_create_s(const GLchar *vertexShaderData, const GLchar *fragmentShaderData);
void shader_free(Shader *s);
void shader_bind(Shader *s);
void shader_unbind(Shader *s);

GLuint shader_get_attrib_loc(Shader *s, const char *name);

void shader_set_uniform_3f(Shader *s, const char *attrib, float p1, float p2, float p3);
void shader_set_uniform_vec3(Shader *s, const char *attrib, Vec3 p1);
void shader_set_uniform_2f(Shader *s, const char *attrib, float p1, float p2);
void shader_set_uniform_1i(Shader *s, const char *attrib, int p1);
void shader_set_uniform_1f(Shader *s, const char *attrib, float p1);
void shader_set_uniform_mat4(Shader *s, const char *attrib, Mat4 p1);

/* File IO helper functions */
static int load_shader_source(const char *filepath, char **bufferPointer);
static long get_file_size(const char *filepath);
static GLint create_shader_program(Shader *s);

#endif