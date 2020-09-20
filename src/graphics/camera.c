#include "camera.h"
#include "../input.h"
#include <stdlib.h>

Camera *camera_create(float speed){
    Camera *cam;

    cam = (Camera *)malloc(sizeof(Camera));
    if(cam == NULL){
        return NULL;
    }

    mat4_identify(&cam->view);
    cam->position.x = 0.0;
    cam->position.y = 0.0;
    cam->position.z = 0.0;

    cam->front.x = 0.0;
    cam->front.y = 0.0;
    cam->front.z = -1.0;

    cam->up.x = 0.0;
    cam->up.y = 1.0;
    cam->up.z = 0.0;

    cam->speed = speed;
    return cam;
}

void camera_free(Camera *cam){
    if(cam != NULL){
        free(cam);
    }
}

void camera_update(Camera *cam, Window *window){
    // TODO: use delta time in position change calculation

    if(input_is_key_pressed(window, KEY_S)){
        cam->position.x += cam->speed * cam->front.x;
        cam->position.y += cam->speed * cam->front.y;
        cam->position.z += cam->speed * cam->front.z;
    }
    
    if(input_is_key_pressed(window, KEY_W)){
        cam->position.x -= cam->speed * cam->front.x;
        cam->position.y -= cam->speed * cam->front.y;
        cam->position.z -= cam->speed * cam->front.z;
    }
    
    if(input_is_key_pressed(window, KEY_D)){
        Vec3 x;
        vec3_cross(&x, &cam->front, &cam->up);
        vec3_normalize(&x, &x);
        cam->position.x -= cam->speed * x.x;
        cam->position.y -= cam->speed * x.y;
        cam->position.z -= cam->speed * x.z;
    }
    
    if(input_is_key_pressed(window, KEY_A)){
        Vec3 x;
        vec3_cross(&x, &cam->front, &cam->up);
        vec3_normalize(&x, &x);
        cam->position.x += cam->speed * x.x;
        cam->position.y += cam->speed * x.y;
        cam->position.z += cam->speed * x.z;
    }
    
    if(input_is_key_pressed(window, KEY_SPACE)){
        cam->position.x += cam->up.x * cam->speed;
        cam->position.y += cam->up.y * cam->speed;
        cam->position.z += cam->up.z * cam->speed;
    }
    
    if(input_is_key_pressed(window, KEY_SHIFT_LEFT)){
        cam->position.x -= cam->up.x * cam->speed;
        cam->position.y -= cam->up.y * cam->speed;
        cam->position.z -= cam->up.z * cam->speed;
    }

    Vec3 sum;
    vec3_add(&sum, &cam->position, &cam->front);
    mat4_look_at(&cam->view, cam->position, sum, cam->up);
}

Mat4 camera_get_view(Camera *cam){
    Mat4 r;
    mat4_set(&r, &cam->view);
    return r;
}