#ifndef _ADAPTLIBS_H
#define _ADAPTLIBS_H

#include "adaptTypes.h"

void panic_a(const char* err);

void *malloc_a(size_t_a size);

void *memset_a(void *str, int c, size_t_a n);

void free_a(void *ptr);

void *realloc_a(void *ptr, size_t_a size);

int debug_out(const char *format, ...);

#define ASSERT_A(COND,ERR) do {if(!COND) panic_a(ERR);} while(0)

//1:small endian,0:big endian
int endian();

#endif