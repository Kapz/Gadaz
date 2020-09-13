#include "vertexArray.h"
#include <stdlib.h>

#include "../engine.h"
#include "../util.h"

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

void va_apply_layout(VertexArray *array, VertexBufferLayout *layout){
    unsigned int stride = 0;
    unsigned int index = 0;
    /* Loop through all elements in the layout and
       add them to the VertexArray*/
    for(int i = 0; i < layout->elementCount; i++){
        Element *e = (layout->elements + i);
        stride += util_type_size(e->type) * e->count;
        va_attrib_pointer(array, index, e->count, e->type, e->normalized, stride, NULL);
        index += 1;
    }
}

void va_attrib_pointer(VertexArray *array, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer){
    /* Now we rebind everytime we want call the function*/
    // TODO: Change? Read above
    va_bind(array);
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(index);
}
