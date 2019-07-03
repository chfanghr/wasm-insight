#include "../data/buffer/buffer.h"
#include "../data/array/array.h"

void test_buffer() {
    buffer b = buffer_init(sizeof(int));
    for (int i = 0; i < 10; i++) {
        array a = array_from_array(&i, 1, sizeof(int));
        buffer_write(b, a, 1);
    }
    array res;
    buffer_read(&res, b, 10);
    for (int i = 0; i < 10; i++) {
        int re = 0;
        array_get(&re, res, i);
        TEST_ASSERT_EQUAL_INT(i, re);
    }
    buffer_destroy(b);
}