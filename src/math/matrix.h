#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

#define PI 3.14159265358979323846

typedef struct{
    float data[16];
}Mat4;

void mat4_set(Mat4 *dest, Mat4 *a);
void mat4_identify(Mat4 *dest); //TODO: Is this name correct?

void mat4_add(Mat4 *dest, Mat4 *a, Mat4 *b);
void mat4_sub(Mat4 *dest, Mat4 *a, Mat4 *b);

void mat4_mul(Mat4 *dest, Mat4 *a, Mat4 *b);
void mat4_mul_s(Mat4 *dest, Mat4 *a, float b);
void mat4_mul_vec3(Vec3 *dest, Mat4 *a, Vec3 *b);
void mat4_mul_vec4(Vec4 *dest, Mat4 *a, Vec4 *b);

void mat4_rotate(Mat4 *dest, Mat4 *a, float angle, Vec3 *b);
void mat4_scale(Mat4 *dest, Mat4 *a, Vec3 *b);
void mat4_translate(Mat4 *dest, Mat4 *a, Vec3 *b);

void mat4_look_at(Mat4 *dest, Vec3 eye, Vec3 center, Vec3 up);
void mat4_frustum(Mat4 *dest, float left, float right, float bottom, float top, float near, float far);
void mat4_ortho(Mat4 *dest, float left, float right, float bottom, float top, float near, float far);
void mat4_perspective(Mat4 *dest, float fovy, float aspect, float near, float far);

#endif