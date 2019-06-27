#include "byteReaders.h"

#include <stdio.h>

bt8 readByte8(BUFFER* buf,size_t* offset){
    if(BUFFER_SIZE(*buf)<1){
        fputs("read byte fail!\n", stderr);
        abort();
    }
    bt8 res = BUFFER_DATA(*buf)[*offset];
    *offset += sizeof(bt8);
    return res;
}