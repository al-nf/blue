#ifndef VEC_H
#define VEC_H

typedef struct vec2 {
    float x;
    float y;
} vec2;

static inline vec2 add(vec2 a, vec2 b) {
    return (vec2){a.x + b.x, a.y + b.y};
}

static inline vec2 sub(vec2 a, vec2 b) {
    return (vec2){a.x - b.x, a.y - b.y};
}

static inline vec2 scale(vec2 v, float s) {
    return (vec2){v.x * s, v.y * s};
}

static inline float dot(vec2 a, vec2 b) {
    return a.x * b.x + a.y * b.y;
}
#endif // VEC_H
