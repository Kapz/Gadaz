#include "VertexArray.h"
#include <stdlib.h>
#include "../engine.h"

VertexArray *va_create(void){
    VertexArray *vertexArray;

    vertexArray = (VertexArray *)malloc(sizeof(VertexArray));
    if(vertexArray == NULL){
        engine_logs("Failed to allocate memory for vertex array\n");
        return NULL;
    }

    glGenVertexArrays(1, &vertexArray->vao);
    return vertexArray;
}

void va_free(VertexArray *vertexArray){
    glDeleteVertexArrays(1, &vertexArray->vao);

    if(vertexArray != NULL){
        free(vertexArray);
    }
}


void va_bind(VertexArray *vertexArray){
    glBindVertexArray(vertexArray->vao);
}

void va_unbind(VertexArray *vertexArray){
    glBindVertexArray(0);
}

void va_attrib_pointer(VertexArray *vertexArray, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer){
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(index);
}
