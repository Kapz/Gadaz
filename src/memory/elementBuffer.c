#include "elementBuffer.h"
#include "../engine.h"
#include <stdlib.h>

ElementBuffer *eb_create(GLsizeiptr size, const GLvoid *data){
    ElementBuffer *eb;
    eb = (ElementBuffer *)malloc(sizeof(ElementBuffer));

    if(eb == NULL){
        engine_logs("Failed to allocate memory for elementbuffer\n");
        return NULL;
    }

    glGenBuffers(1, &eb->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

    return eb;
}

void eb_free(ElementBuffer *eb){
    glDeleteBuffers(1, &eb->ebo);
    free(eb);
}


void eb_bind(ElementBuffer *eb){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb->ebo);
}

void eb_unbind(ElementBuffer *eb){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
