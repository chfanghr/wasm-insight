#include <datas/str.h>
#include <datas/readers/readers.h>
#include "unity/unity.h"

void test_i64_read() {
    byte data[3] = {0xE9, 0xBB, 0x07};
    BUFFER b;
    BUFFER_INIT(b, 3, 0);
    BUFFER_FILL(b, 0, data, 3);
    u64 res = readUint64(&b, 0);
    TEST_ASSERT_EQUAL_UINT64((u64) 122345, res);
}