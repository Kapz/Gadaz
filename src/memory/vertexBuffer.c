#include "vertexBuffer.h"
#include "../engine.h"
#include <stdlib.h>

VertexBuffer *vb_create(GLsizeiptr size, const GLvoid *data){
    VertexBuffer *buffer;

    buffer = malloc(sizeof(VertexBuffer));
    if(buffer == NULL){
        engine_logs("Failed to allocate memory for vertex buffer object\n");
        return NULL;
    }

    glGenBuffers(1, &buffer->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, buffer->vbo);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

    return buffer;
}

void vb_free(VertexBuffer *buffer){
    glDeleteBuffers(1, &buffer->vbo);
    free(buffer);
}


void vb_bind(VertexBuffer *buffer){
    glBindBuffer(GL_ARRAY_BUFFER, buffer->vbo);
}

void vb_unbind(VertexBuffer *buffer){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}