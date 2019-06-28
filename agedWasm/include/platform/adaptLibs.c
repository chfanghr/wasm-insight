#include "adaptLibs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void panic_a(const char* err){
    fputs(err,stderr);
    abort();
}

void *malloc_a(size_t_a size){
    return malloc(size);
}

void *memset_a(void *str, int c, size_t_a n){
    return memset(str,c,n);
}

void free_a(void *ptr){
    free(ptr);
}

void *realloc_a(void *ptr, size_t_a size){
    return realloc(ptr,size);
}

int debug_out(const char *format, ...){
    va_list args;
    va_start(args, format);
    int res = vprintf(format, args);
    va_end(args);
    return res;
}

int endian() {
    int a = 0x01;
    return (((u8_a *) (&a))[0] == (u8_a) 1) ? 1 : 0;
}

