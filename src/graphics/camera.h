#ifndef CAMERA_H
#define CAMERA_H

#include "../math/vector.h"
#include "../math/matrix.h"
#include "../window.h"

typedef struct{
    Mat4 view;
    Vec3 position;
    Vec3 front;
    Vec3 up;

    float speed;
}Camera;

Camera *camera_create(float speed);
void camera_free(Camera *cam);

void camera_update(Camera *cam, Window *window);
Mat4 camera_get_view(Camera *cam);

#endif