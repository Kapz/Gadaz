#ifndef ELEMENT_BUFFER_H
#define ELEMENT_BUFFER_H

#include <GL/glew.h>

typedef struct ElementBuffer{
    GLuint ebo;
}ElementBuffer;

ElementBuffer *eb_create(GLsizeiptr size, const GLvoid *data);
void eb_free(ElementBuffer *eb);

void eb_bind(ElementBuffer *eb);
void eb_unbind(ElementBuffer *eb);

#endif