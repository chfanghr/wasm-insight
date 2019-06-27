#include "byteReaders.h"

#include <stdio.h>

byte readByte8(BUFFER* buf,size_t* offset){
    if(BUFFER_SIZE(*buf)<1){
        fputs("read byte fail!\n", stderr);
        abort();
    }
    byte res = BUFFER_DATA(*buf)[*offset];
    *offset += sizeof(byte);
    return res;
}