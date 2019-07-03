//
// Created by 31838 on 7/3/2019.
//

#ifndef AGEDWASM_ARRAY_H
#define AGEDWASM_ARRAY_H

#include "../data/array/array.h"
#include "../data/type.h"
#include "unity/unity.h"

void test_array() {
    array a = array_init(10, sizeof(byte));
    for (byte i = 0; i < 10; i++)
        array_set(a, (int) i, &i);
    for (byte i = 0; i < 10; i++) {
        byte re;
        array_get(&re, a, (int) i);
        TEST_ASSERT_EQUAL_UINT8((uint8_t) i, (uint8_t) re);
    }
}

#endif //AGEDWASM_ARRAY_H
