#include "VertexBuffer.h"
#include "../engine.h"
#include <stdlib.h>

VertexBuffer *vb_create(GLsizeiptr size, const GLvoid *data){
    VertexBuffer *vertexBuffer;

    vertexBuffer = malloc(sizeof(VertexBuffer));
    if(vertexBuffer == NULL){
        engine_logs("Failed to allocate memory for vertex buffer object\n");
        return NULL;
    }

    glGenBuffers(1, &vertexBuffer->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->vbo);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

    return vertexBuffer;
}

void vb_free(VertexBuffer *vertexBuffer){
    glDeleteBuffers(1, &vertexBuffer->vbo);
    free(vertexBuffer);
}


void vb_bind(VertexBuffer *vertexBuffer){
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->vbo);
}

void vb_unbind(VertexBuffer *vertexBuffer){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}