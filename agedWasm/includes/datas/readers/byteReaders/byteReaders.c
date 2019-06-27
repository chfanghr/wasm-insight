#include "byteReaders.h"

#include <platform/adaptLibs.h>

byte readByte8(BUFFER* buf,siz_t* offset){
    if(BUFFER_SIZE(*buf)<1){
        panic_a("read bytes failed!\n");
    }
    byte res = BUFFER_DATA(*buf)[*offset];
    *offset += sizeof(byte);
    return res;
}