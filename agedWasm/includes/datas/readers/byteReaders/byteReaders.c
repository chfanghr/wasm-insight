#include "byteReaders.h"

#include <platform/adaptLibs.h>

byte readByte8(BUFFER* buf,siz_t* offset){
    ASSERT_A((BUFFER_SIZE(*buf)<1),"read bytes failed!\n");
    byte res = BUFFER_DATA(*buf)[*offset];
    *offset += sizeof(byte);
    return res;
}