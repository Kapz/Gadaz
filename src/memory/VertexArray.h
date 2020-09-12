#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <GL/glew.h>

typedef struct VertexArray{
    GLuint vao;
}VertexArray;

VertexArray *va_create(void);
void va_free(VertexArray *array);

void va_bind(VertexArray *array);
void va_unbind(VertexArray *array);
void va_attrib_pointer(VertexArray *array, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);

#endif