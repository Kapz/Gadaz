#include "matrix.h"
#include <math.h>

void mat4_set(Mat4 *dest, Mat4 *a){
    dest->data[0] = a->data[0];
    dest->data[1] = a->data[1];
    dest->data[2] = a->data[2];
    dest->data[3] = a->data[3];
    dest->data[4] = a->data[4];
    dest->data[5] = a->data[5];
    dest->data[6] = a->data[6];
    dest->data[7] = a->data[7];
    dest->data[8] = a->data[8];
    dest->data[9] = a->data[9];
    dest->data[10] = a->data[10];
    dest->data[11] = a->data[11];
    dest->data[12] = a->data[12];
    dest->data[13] = a->data[13];
    dest->data[14] = a->data[14];
    dest->data[15] = a->data[15];
}

void mat4_add(Mat4 *dest, Mat4 *a, Mat4 *b){
    dest->data[0] = a->data[0] + b->data[0];
    dest->data[1] = a->data[1] + b->data[1];
    dest->data[2] = a->data[2] + b->data[2];
    dest->data[3] = a->data[3] + b->data[3];
    dest->data[4] = a->data[4] + b->data[4];
    dest->data[5] = a->data[5] + b->data[5];
    dest->data[6] = a->data[6] + b->data[6];
    dest->data[7] = a->data[7] + b->data[7];
    dest->data[8] = a->data[8] + b->data[8];
    dest->data[9] = a->data[9] + b->data[9];
    dest->data[10] = a->data[10] + b->data[10];
    dest->data[11] = a->data[11] + b->data[11];
    dest->data[12] = a->data[12] + b->data[12];
    dest->data[13] = a->data[13] + b->data[13];
    dest->data[14] = a->data[14] + b->data[14];
    dest->data[15] = a->data[15] + b->data[15];
}
void mat4_sub(Mat4 *dest, Mat4 *a, Mat4 *b){
    dest->data[0] = a->data[0] - b->data[0];
    dest->data[1] = a->data[1] - b->data[1];
    dest->data[2] = a->data[2] - b->data[2];
    dest->data[3] = a->data[3] - b->data[3];
    dest->data[4] = a->data[4] - b->data[4];
    dest->data[5] = a->data[5] - b->data[5];
    dest->data[6] = a->data[6] - b->data[6];
    dest->data[7] = a->data[7] - b->data[7];
    dest->data[8] = a->data[8] - b->data[8];
    dest->data[9] = a->data[9] - b->data[9];
    dest->data[10] = a->data[10] - b->data[10];
    dest->data[11] = a->data[11] - b->data[11];
    dest->data[12] = a->data[12] - b->data[12];
    dest->data[13] = a->data[13] - b->data[13];
    dest->data[14] = a->data[14] - b->data[14];
    dest->data[15] = a->data[15] - b->data[15];
}

void mat4_mul(Mat4 *dest, Mat4 *a, Mat4 *b){
    dest->data[0] = a->data[0] * b->data[0] + a->data[1] * b->data[3] + a->data[2] * b->data[8] + a->data[3] * b->data[12];
    dest->data[1] = a->data[0] * b->data[1] + a->data[1] * b->data[5] + a->data[2] * b->data[9] + a->data[3] * b->data[13];
    dest->data[2] = a->data[0] * b->data[2] + a->data[1] * b->data[6] + a->data[2] * b->data[10] + a->data[3] * b->data[14];
    dest->data[3] = a->data[0] * b->data[3] + a->data[1] * b->data[7] + a->data[2] * b->data[11] + a->data[3] * b->data[15];

    dest->data[4] = a->data[4] * b->data[0] + a->data[5] * b->data[3] + a->data[6] * b->data[8] + a->data[7] * b->data[12];
    dest->data[5] = a->data[4] * b->data[1] + a->data[5] * b->data[5] + a->data[6] * b->data[9] + a->data[7] * b->data[13];
    dest->data[6] = a->data[4] * b->data[2] + a->data[5] * b->data[6] + a->data[6] * b->data[10] + a->data[7] * b->data[14];
    dest->data[7] = a->data[4] * b->data[3] + a->data[5] * b->data[7] + a->data[6] * b->data[11] + a->data[7] * b->data[15];
    
    dest->data[8] = a->data[8] * b->data[0] + a->data[9] * b->data[3] + a->data[10] * b->data[8] + a->data[11] * b->data[12];
    dest->data[9] = a->data[8] * b->data[1] + a->data[9] * b->data[5] + a->data[10] * b->data[9] + a->data[11] * b->data[13];
    dest->data[10] = a->data[8] * b->data[2] + a->data[9] * b->data[6] + a->data[10] * b->data[10] + a->data[11] * b->data[14];
    dest->data[11] = a->data[8] * b->data[3] + a->data[9] * b->data[7] + a->data[10] * b->data[11] + a->data[11] * b->data[15];
    
    dest->data[12] = a->data[12] * b->data[0] + a->data[13] * b->data[3] + a->data[14] * b->data[8] + a->data[15] * b->data[12];
    dest->data[13] = a->data[12] * b->data[1] + a->data[13] * b->data[5] + a->data[14] * b->data[9] + a->data[15] * b->data[13];
    dest->data[14] = a->data[12] * b->data[2] + a->data[13] * b->data[6] + a->data[14] * b->data[10] + a->data[15] * b->data[14];
    dest->data[15] = a->data[12] * b->data[3] + a->data[13] * b->data[7] + a->data[14] * b->data[11] + a->data[15] * b->data[15];
}

void mat4_mul_s(Mat4 *dest, Mat4 *a, float b){
    dest->data[0] = a->data[0] * b;
    dest->data[1] = a->data[1] * b;
    dest->data[2] = a->data[2] * b;
    dest->data[3] = a->data[3] * b;
    dest->data[4] = a->data[4] * b;
    dest->data[5] = a->data[5] * b;
    dest->data[6] = a->data[6] * b;
    dest->data[7] = a->data[7] * b;
    dest->data[8] = a->data[8] * b;
    dest->data[9] = a->data[9] * b;
    dest->data[10] = a->data[10] * b;
    dest->data[11] = a->data[11] * b;
    dest->data[12] = a->data[12] * b;
    dest->data[13] = a->data[13] * b;
    dest->data[14] = a->data[14] * b;
    dest->data[15] = a->data[15] * b;
}

void mat4_mul_vec3(Vec3 *dest, Mat4 *a, Vec3 *b){
    dest->x = a->data[0] * b->x + a->data[4] * b->y + a->data[8] + b->z + a->data[12];
    dest->y = a->data[1] * b->x + a->data[5] * b->y + a->data[9] + b->z + a->data[13];
    dest->z = a->data[2] * b->x + a->data[6] * b->y + a->data[10] + b->z + a->data[14];
}

void mat4_mul_vec4(Vec4 *dest, Mat4 *a, Vec4 *b){
    b->x = a->data[0] * b->x + a->data[4] * b->y + a->data[8] * b->z + a->data[12] * b->w;
    b->y = a->data[1] * b->x + a->data[5] * b->y + a->data[9] * b->z + a->data[13] * b->w;
    b->z = a->data[2] * b->x + a->data[6] * b->y + a->data[10] * b->z + a->data[14] * b->w;
    b->w = a->data[3] * b->x + a->data[7] * b->y + a->data[11] * b->z + a->data[15] * b->w;
}

void mat4_rotate(Mat4 *dest, Mat4 *a, float angle, Vec3 *b){
    float s = sin(angle);
    float c = cos(angle);
    float t = 1 - c;

    Vec3 axis;
    Mat4 rotate;
    vec3_normalize(&axis, b);
cam->position.x += cam->up.x * cam->speed;
        cam->position.y += cam->up.y * cam->speed;
        cam->position.z += cam->up.z * cam->speed;
    rotate.data[0] = b->x * b->x * t + c;
    rotate.data[1] = b->y * b->x * t + b->z * s;
    rotate.data[2] = b->z * b->x * t - b->y * s;

    rotate.data[4] = b->x * b->y * t - b->z * s;
    rotate.data[5] = b->y * b->y * t + c;
    rotate.data[6] = b->z * b->y * t + b->x * s;

    rotate.data[8] = b->x * b->z * t + b->y * s;
    rotate.data[9] = b->y * b->z * t - b->x * s;
    rotate.data[10] = b->z * b->z * t + c;

    dest->data[0] = a->data[0] * rotate.data[0] + a->data[4] * rotate.data[1] + a->data[8] * rotate.data[2];
    dest->data[1] = a->data[1] * rotate.data[0] + a->data[5] * rotate.data[1] + a->data[9] * rotate.data[2];
    dest->data[2] = a->data[2] * rotate.data[0] + a->data[6] * rotate.data[1] + a->data[10] * rotate.data[2];
    dest->data[3] = a->data[3] * rotate.data[0] + a->data[7] * rotate.data[1] + a->data[11] * rotate.data[2];

    dest->data[4] = a->data[0] * rotate.data[4] + a->data[4] * rotate.data[5] + a->data[8] * rotate.data[6];
    dest->data[5] = a->data[1] * rotate.data[4] + a->data[5] * rotate.data[5] + a->data[9] * rotate.data[6];
    dest->data[6] = a->data[2] * rotate.data[4] + a->data[6] * rotate.data[5] + a->data[10] * rotate.data[6];
    dest->data[7] = a->data[3] * rotate.data[4] + a->data[7] * rotate.data[5] + a->data[11] * rotate.data[6];

    dest->data[8] = a->data[0] * rotate.data[8] + a->data[4] * rotate.data[9] + a->data[8] * rotate.data[10];
    dest->data[9] = a->data[1] * rotate.data[8] + a->data[5] * rotate.data[9] + a->data[9] * rotate.data[10];
    dest->data[10] = a->data[2] * rotate.data[8] + a->data[6] * rotate.data[9] + a->data[10] * rotate.data[10];
    dest->data[11] = a->data[3] * rotate.data[8] + a->data[7] * rotate.data[9] + a->data[11] * rotate.data[10];

    dest->data[12] = a->data[12];
    dest->data[13] = a->data[13];
    dest->data[14] = a->data[14];
    dest->data[15] = a->data[15];
}

void mat4_scale(Mat4 *dest, Mat4 *a, Vec3 *b){
    dest->data[0] = a->data[0] * b->x;
    dest->data[1] = a->data[1];
    dest->data[2] = a->data[2];
    dest->data[3] = a->data[3];
    dest->data[4] = a->data[4];
    dest->data[5] = a->data[5] * b->y;
    dest->data[6] = a->data[6];
    dest->data[7] = a->data[7];
    dest->data[8] = a->data[8];
    dest->data[9] = a->data[9];
    dest->data[10] = a->data[10] * b->z;
    dest->data[11] = a->data[11];
    dest->data[12] = a->data[12];
    dest->data[13] = a->data[13];
    dest->data[14] = a->data[14];
    dest->data[15] = a->data[15];
}

void mat4_translate(Mat4 *dest, Mat4 *a, Vec3 *b){
    dest->data[0] = a->data[0];
    dest->data[1] = a->data[1];
    dest->data[2] = a->data[2];
    dest->data[3] = a->data[3];
    dest->data[4] = a->data[4];
    dest->data[5] = a->data[5];
    dest->data[6] = a->data[6];
    dest->data[7] = a->data[7];
    dest->data[8] = a->data[8];
    dest->data[9] = a->data[9];
    dest->data[10] = a->data[10];
    dest->data[11] = a->data[11];

    dest->data[12] = a->data[0] * b->x + a->data[4] * b->y + a->data[8] * b->z + a->data[12];
    dest->data[13] = a->data[1] * b->x + a->data[5] * b->y + a->data[9] * b->z + a->data[13];
    dest->data[14] = a->data[2] * b->x + a->data[6] * b->y + a->data[10] * b->z + a->data[14];
    dest->data[15] = a->data[3] * b->x + a->data[7] * b->y + a->data[11] * b->z + a->data[15];
}

void mat4_look_at(Mat4 *dest, Vec3 eye, Vec3 center, Vec3 up){
    Vec3 f;
    vec3_sub(&f, &center, &eye);
    vec3_normalize(&f, &f);

    Vec3 s;
    vec3_cross(&s, &up, &f);
    vec3_normalize(&s, &s);

    Vec3 u;
    vec3_cross(&u, &f, &s);
    
    mat4_identify(dest);
    dest->data[0] = s.x;
    dest->data[1] = s.y;
    dest->data[2] = s.z;
    dest->data[3] = 0;
    dest->data[4] = u.x;
    dest->data[5] = u.y;
    dest->data[6] = u.z;
    dest->data[7] = 0;
    dest->data[8] = f.x;
    dest->data[9] = f.y;
    dest->data[10] = f.z;
    dest->data[11] = 0;
    dest->data[12] = -vec3_dot(&s, &eye);
    dest->data[13] = -vec3_dot(&u, &eye);
    dest->data[14] = -vec3_dot(&f, &eye);
}

void mat4_identify(Mat4 *dest){
    dest->data[0] = 1;
    dest->data[1] = 0;
    dest->data[2] = 0;
    dest->data[3] = 0;

    dest->data[4] = 0;
    dest->data[5] = 1;
    dest->data[6] = 0;
    dest->data[7] = 0;

    dest->data[8] = 0;
    dest->data[9] = 0;
    dest->data[10] = 1;
    dest->data[11] = 0;

    dest->data[12] = 0;
    dest->data[13] = 0;
    dest->data[14] = 0;
    dest->data[15] = 1;
}

void mat4_frustum(Mat4 *dest, float left, float right, float bottom, float top, float near, float far){
    float dsides = (right - left);
    float dheight = (top - bottom);
    float ddepth = (far - near);

    dest->data[0] = (2 * near) / dsides;
    dest->data[1] = 0;
    dest->data[2] = 0;
    dest->data[3] = 0;
    dest->data[4] = 0;
    dest->data[5] = (2 * near) / dheight;
    dest->data[6] = 0;
    dest->data[7] = 0;
    dest->data[8] = (right + left) / dsides;
    dest->data[9] = (top + bottom) / dheight;
    dest->data[10] = -((far + near) / ddepth);
    dest->data[11] = -1;
    dest->data[12] = 0;
    dest->data[13] = 0;
    dest->data[14] = -((2 * far * near) / ddepth);
    dest->data[15] = 0;
}

void mat4_ortho(Mat4 *dest, float left, float right, float bottom, float top, float near, float far){
    float dsides = (right - left);
    float dheight = (top - bottom);
    float ddepth = (far - near);

    dest->data[0] = 2 / dsides;
    dest->data[1] = 0;
    dest->data[2] = 0;
    dest->data[3] = 0;
    dest->data[4] = 0;
    dest->data[5] = 2 / dheight;
    dest->data[6] = 0;
    dest->data[7] = 0;
    dest->data[8] = 0;
    dest->data[9] = 0;
    dest->data[10] = -2 / ddepth;
    dest->data[11] = 0;
    dest->data[12] = -((right + left) / dsides);
    dest->data[13] = -((top + bottom) / dheight);
    dest->data[14] = -((far + near) / ddepth);
    dest->data[15] = 1;
}

void mat4_perspective(Mat4 *dest, float fovy, float aspect, float near, float far){
    float top = near * tan(fovy * PI / 360.0);
    float right = top * aspect;

    mat4_frustum(dest, -right, right, -top, top, near, far);
}