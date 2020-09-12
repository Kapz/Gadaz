#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <GL/glew.h>

typedef struct VertexBuffer{
    GLuint vbo;
}VertexBuffer;

VertexBuffer *vb_create(GLsizeiptr size, const GLvoid *data);
void vb_free(VertexBuffer *vertexBuffer);

void vb_bind(VertexBuffer *vertexBuffer);
void vb_unbind(VertexBuffer *vertexBuffer);

#endif