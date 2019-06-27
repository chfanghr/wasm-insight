#ifndef _UINTREADERS_H
#define _UINTREADERS_H

#include <datas/buffer.h>
#include <datas/types.h>

u64 readUint64(BUFFER* buf,size_t* offset);
u32 readUint32(BUFFER* buf,size_t* offset);

#endif