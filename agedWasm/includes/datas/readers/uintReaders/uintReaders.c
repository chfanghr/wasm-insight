#include "uintReaders.h"

#include <platform/adaptLibs.h>

u64 readUint64(BUFFER *buf, siz_t *offset) {
    u64 res = 0;
    byte b = 0;
    i32 s = 0;
    u32 i = 0;
    for (i = 0;; i++) {
        ASSERT_A(!(i >= BUFFER_SIZE(*buf)), "read u64 failed!\n");
        BUFFER_READ(*buf, i + *offset, &b, sizeof(byte));
        if (b < 0x80) {
            ASSERT_A(!(i > 9 || i == 9 && b > 1), "read u64 overflow!\n");
            *offset += (i + 1) * sizeof(byte);
            res |= (u64) b << s;
            return res;
        }
        res |= (u64) (b & 0x7f) << s;
        s += 7;
    }
}

u32 readUint32(BUFFER *buf, siz_t *offset) {
    u32 res = 0;
    byte b = 0;
    i32 s = 0;
    u32 i = 0;
    for (i = 0;; i++) {
        ASSERT_A(!(i >= BUFFER_SIZE(*buf)), "read u32 failed!\n");
        BUFFER_READ(*buf, i + *offset, &b, sizeof(byte));
        if (b < 0x80) {
            ASSERT_A(!(i > 5 || i == 5 && b > 1), "read u32 overflow!\n");
            *offset += (i + 1) * sizeof(byte);
            res |= (u32) b << s;
            return res;
        }
        res |= (u32) (b & 0x7f) << s;
        s += 7;
    }
}