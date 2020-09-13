#ifndef VECTOR_H
#define VECTOR_H

typedef struct __attribute__((__packed__)) Vec3{
    double x;
    double y;
    double z;
}Vec3;

typedef struct __attribute__((__packed__)) Vec4{
    double x;
    double y;
    double z;
    double w;
}Vec4;

void vec3_add(Vec3 *dest, Vec3 *a, Vec3 *b);
void vec3_sub(Vec3 *dest, Vec3 *a, Vec3 *b);

void vec3_mul_s(Vec3 *dest, Vec3 *a, double b);
void vec3_div_s(Vec3 *dest, Vec3 *a, double b);

void vec3_cross(Vec3 *dest, Vec3 *a, Vec3 *b);
void vec3_normalize(Vec3 *dest, Vec3 *a);

double vec3_dot(Vec3 *a, Vec3 *b);

#endif