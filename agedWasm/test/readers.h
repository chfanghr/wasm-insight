#include <datas/buffer.h>
#include <datas/readers/readers.h>

void test_readers() {
    BUFFER buf;
    BUFFER_INIT(buf,0,0x00);
    readByte8(&buf,0);
    BUFFER_FREE(buf);
}