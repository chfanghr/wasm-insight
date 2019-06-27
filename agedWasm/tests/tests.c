//
// Created by 31838 on 6/28/2019.
//

#include "unity/unity.h"
#include "buffer.h"
#include "readers.h"
#include "decoder.h"
#include "vector.h"
#include "i64read.h"

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_buffer);
    RUN_TEST(test_decoder);
//    RUN_TEST(test_readers);
    RUN_TEST(test_vector);
    RUN_TEST(test_i64_read);
    return UNITY_END();
}