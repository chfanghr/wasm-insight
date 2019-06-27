#ifndef _VECTOR_H
#define _VECTOR_H

#include <stdlib.h>
#include <stdio.h>

/* Declare a vector of type `TYPE`. */
#define VECTOR_OF(TYPE) struct { \
    TYPE *data; \
    size_t size; \
    size_t capacity; \
}

/* Initialize `VEC` with `N` capacity. */
#define VECTOR_INIT_CAPACITY(VEC, N) do { \
    (VEC).data = malloc((N) * sizeof(*(VEC).data)); \
    if (!(VEC).data) { \
        fputs("malloc failed!\n", stderr); \
        abort(); \
    } \
    (VEC).size = 0; \
    (VEC).capacity = (N); \
} while (0)

/* Initialize `VEC` with zero elements. */
#define VECTOR_INIT(VEC) VECTOR_INIT_CAPACITY(VEC, 1)

/* Get the amount of elements in `VEC`. */
#define VECTOR_SIZE(VEC) (VEC).size

/* Get the amount of elements that are allocated for `VEC`. */
#define VECTOR_CAPACITY(VEC) (VEC).capacity

/* Test if `VEC` is empty. */
#define VECTOR_EMPTY(VEC) ((VEC).size == 0)

/* Push `VAL` at the back of the vector. This function will reallocate the buffer if
   necessary. */
#define VECTOR_PUSH_BACK(VEC, VAL) do { \
    if ((VEC).size + 1 > (VEC).capacity) { \
        size_t n = (VEC).capacity * 2; \
        void *p = realloc((VEC).data, n * sizeof(*(VEC).data)); \
        if (!p) { \
            fputs("realloc failed!\n", stderr); \
            abort(); \
        } \
        (VEC).data = p; \
        (VEC).capacity = n; \
    } \
    (VEC).data[VECTOR_SIZE(VEC)] = (VAL); \
    (VEC).size += 1; \
} while (0)

/* Get the value of `VEC` at `INDEX`. */
#define VECTOR_AT(VEC, INDEX) (VEC).data[INDEX]

/* Get the value at the front of `VEC`. */
#define VECTOR_FRONT(VEC) (VEC).data[0]

/* Get the value at the back of `VEC`. */
#define VECTOR_BACK(VEC) (VEC).data[VECTOR_SIZE(VEC) - 1]

#define VECTOR_FREE(VEC) do { \
    (VEC).size = 0; \
    (VEC).capacity = 0; \
    free((VEC).data); \
} while(0)

#endif /* !defined VECTOR_H_ */