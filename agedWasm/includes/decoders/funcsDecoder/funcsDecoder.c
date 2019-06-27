#include "funcsDecoder.h"

#include <datas/readers/uintReaders/uintReaders.h>
#include <datas/readers/byteReaders/byteReaders.h>
#include <platform/adaptLibs.h>

funcsObject_t* decodeFuncs(BUFFER* buf){
    siz_t offset = 0;
    u32 funcsCount = readUint32(buf,&offset);
    debug_out("funcsCount: %d\n",funcsCount);
}