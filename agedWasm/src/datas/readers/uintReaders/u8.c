//
// Created by 31838 on 6/28/2019.
//

#include <platform/adaptLibs.h>
#include "u8.h"

u8 revert_u8_endian(u8 b) {
    u8 i, p, *stack = malloc_a(sizeof(b) * 8);
    if (!stack)panic_a("malloc failed");

    for (i = 0, p = 0b10000000; i < sizeof(b); i++, p >>= (u8) 1)
        stack[i] = (u8) (b & p ? 1 : 0);

    for (p = 0b00000001, b = 0b00000000; i >= 0; i--, p <<= (u8) 1)
        if (stack[i])b |= p;

    return b;
}

u8 *revert_u8_array_endian_in_place(u8 *arr, siz_t len) {
    u8 i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        arr[i] = revert_u8_endian(arr[i]);
        arr[j] = revert_u8_endian(arr[j]);
        swap_u8_array_element_in_place(arr, len, i, j);
    }
    return arr;
}

u8 *swap_u8_array_element_in_place(u8 *arr, siz_t len, siz_t a, siz_t b) {
    u8 tmp;
    if (a < len && b < len) {
        tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
        return arr;
    }
    panic_a("index out of range");
    //unreachable
    return arr;
}