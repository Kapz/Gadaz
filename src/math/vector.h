#ifndef VECTOR_H
#define VECTOR_H

typedef struct __attribute__((__packed__)){
    float x;
    float y;
}Vec2;

typedef struct __attribute__((__packed__)){
    float x;
    float y;
    float z;
}Vec3;

typedef struct __attribute__((__packed__)){
    float x;
    float y;
    float z;
    float w;
}Vec4;

void vec3_set(Vec3 *dest, Vec3 a);

void vec3_add(Vec3 *dest, Vec3 *a, Vec3 *b);
void vec3_sub(Vec3 *dest, Vec3 *a, Vec3 *b);

void vec3_mul_s(Vec3 *dest, Vec3 *a, float b);
void vec3_div_s(Vec3 *dest, Vec3 *a, float b);

void vec3_cross(Vec3 *dest, Vec3 *a, Vec3 *b);
void vec3_normalize(Vec3 *dest, Vec3 *a);

float vec3_dot(Vec3 *a, Vec3 *b);

#endif