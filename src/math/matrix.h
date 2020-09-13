#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

typedef struct __attribute__((__packed__)) Mat4{
    double data[16];
}Mat4;

void mat4_add(Mat4 *dest, Mat4 *a, Mat4 *b);
void mat4_sub(Mat4 *dest, Mat4 *a, Mat4 *b);

void mat4_mul(Mat4 *dest, Mat4 *a, Mat4 *b);
void mat4_mul_s(Mat4 *dest, Mat4 *a, double b);
void mat4_mul_vec3(Vec3 *dest, Mat4 *a, Vec3 *b);
void mat4_mul_vec4(Vec4 *dest, Mat4 *a, Vec4 *b);

void mat4_rotate(Mat4 *dest, Mat4 *a, double angle, Vec3 *b);
void mat4_scale(Mat4 *dest, Mat4 *a, Vec3 *b);
void mat4_translate(Mat4 *dest, Mat4 *a, Vec3 *b);
void mat4_identify(Mat4 *dest);

#endif