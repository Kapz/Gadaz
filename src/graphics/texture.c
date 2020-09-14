#include "texture.h"
#include "../engine.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../external/stb_image.h"

Texture *texture_create(const char *filePath){
    Texture *tex;
    tex = (Texture *)malloc(sizeof(Texture));

    if(tex == NULL){
        engine_logs("Failed to allocate memory for texture\n");
        return NULL;
    }

    glGenTextures(1, &tex->id);

    if(load_from_file(tex, filePath)){
        engine_logs("Failed to read texture data from file\n");
        glDeleteTextures(1, &tex->id);
        return NULL;
    }
    
    return tex;
}

void texture_free(Texture *tex){
    glDeleteTextures(1, &tex->id);
    free(tex);
}


void texture_bind(Texture *tex){
    glBindTexture(GL_TEXTURE_2D, tex->id);
}

void texture_bind_to_slot(Texture *tex, unsigned int slot){
    glActiveTexture(GL_TEXTURE0 + slot);
}


void texture_set_parameter_i(GLenum target, GLenum parameter, GLint param){
    glTexParameteri(target, parameter, param);
}
void texture_set_parameter_f(GLenum target, GLenum parameter, GLfloat param){
    glTexParameterf(target, parameter, param);
}

GLuint texture_get_id(Texture *tex){
    return tex->id;
}


static int load_from_file(Texture *tex, const char *filePath){
    unsigned char *textureData;
    int channelCount;

    stbi_set_flip_vertically_on_load(1);
    textureData = stbi_load(filePath, &tex->width, &tex->height, &channelCount, STBI_rgb);

    if(textureData == NULL){
        return 1;
    }

    texture_bind(tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex->width, tex->height, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(textureData);
    return 0;
}
