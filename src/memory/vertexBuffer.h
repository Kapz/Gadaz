#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <GL/glew.h>

typedef struct{
    GLuint vbo;
}VertexBuffer;

VertexBuffer *vb_create(GLsizeiptr size, const GLvoid *data);
void vb_free(VertexBuffer *buffer);

void vb_bind(VertexBuffer *buffer);
void vb_unbind(VertexBuffer *buffer);

#endif