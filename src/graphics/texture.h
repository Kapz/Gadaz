#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

typedef struct{
    GLuint id;
    int width;
    int height;
}Texture;

Texture *texture_create(const char *filePath);
void texture_free(Texture *tex);

void texture_bind(Texture *tex);
void texture_bind_to_slot(Texture *tex, unsigned int slot);

void texture_set_parameter_i(GLenum target, GLenum parameter, GLint param);
void texture_set_parameter_f(GLenum target, GLenum parameter, GLfloat param);
GLuint texture_get_id(Texture *tex);

static int load_from_file(Texture *tex, const char *filePath);

#endif