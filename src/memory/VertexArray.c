#include "VertexArray.h"
#include <stdlib.h>
#include "../engine.h"

VertexArray *va_create(void){
    VertexArray *array;

    array = (VertexArray *)malloc(sizeof(VertexArray));
    if(array == NULL){
        engine_logs("Failed to allocate memory for vertex array\n");
        return NULL;
    }

    glGenVertexArrays(1, &array->vao);
    return array;
}

void va_free(VertexArray *array){
    glDeleteVertexArrays(1, &array->vao);

    if(array != NULL){
        free(array);
    }
}


void va_bind(VertexArray *array){
    glBindVertexArray(array->vao);
}

void va_unbind(VertexArray *array){
    glBindVertexArray(0);
}

void va_attrib_pointer(VertexArray *array, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer){
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(index);
}
