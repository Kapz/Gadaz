#include "vector.h"
#include <math.h>

void vec3_add(Vec3 *dest, Vec3 *a, Vec3 *b){
    dest->x = a->x + b->x;
    dest->y = a->y + b->y;
    dest->z = a->z + b->z;
}

void vec3_sub(Vec3 *dest, Vec3 *a, Vec3 *b){
    dest->x = a->x - b->x;
    dest->y = a->y - b->y;
    dest->z = a->z - b->z;
}

void vec3_mul_s(Vec3 *dest, Vec3 *a, double b){
    dest->x = a->x * b;
    dest->y = a->y * b;
    dest->z = a->z * b;
}

void vec3_div_s(Vec3 *dest, Vec3 *a, double b){
    dest->x = a->x / b;
    dest->y = a->y / b;
    dest->z = a->z / b;
}

void vec3_cross(Vec3 *dest, Vec3 *a, Vec3 *b){
    dest->x = a->y * b->z - a->z * b->y;
    dest->y = a->z * b->x - a->x * b->z;
    dest->z = a->x * b->y - a->y * b->x;
}

void vec3_normalize(Vec3 *dest, Vec3 *a){
    double length = sqrt((a->x * a->x) + (a->y * a->y) + (a->z * a->z));

    dest->x /= length;
    dest->y /= length;
    dest->z /= length;
}

double vec3_dot(Vec3 *a, Vec3 *b){
    return a->x * b->x + a->y * b->y + a->z * b->z;
}