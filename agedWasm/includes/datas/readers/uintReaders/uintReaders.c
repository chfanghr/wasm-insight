#include "uintReaders.h"

#include <stdio.h>

u64 readUint64(BUFFER* buf,size_t* offset){
    u64 res = 0;
    bt8 b = 0;
    int s = 0;
    int i = 0;
    for(i=0;;i++){
        if(i>=BUFFER_SIZE(*buf)){
            fputs("read u64 fail!\n", stderr);
            abort();
        }
        BUFFER_READ(*buf,i+*offset,&b,sizeof(bt8));
        if(b<0x80){
            if(i>9 || i==9&&b>1){
                fputs("read u64 overflow!\n", stderr);
                abort();
            }
            *offset += (i+1)*sizeof(bt8);
            res |= (u64)b << s;
            return res;
        }
        res |= (u64)(b&0x7f) << s;
        s+=7;
    }
}

u32 readUint32(BUFFER* buf,size_t* offset){
    u32 res = 0;
    bt8 b = 0;
    int s = 0;
    int i = 0;
    for(i=0;;i++){
        if(i>=BUFFER_SIZE(*buf)){
            fputs("read u32 fail!\n", stderr);
            abort();
        }
        BUFFER_READ(*buf,i+*offset,&b,sizeof(bt8));
        if(b<0x80){
            if(i>5 || i==5&&b>1){
                fputs("read u32 overflow!\n", stderr);
                abort();
            }
            *offset += (i+1)*sizeof(bt8);
            res |= (u32)b << s;
            return res;
        }
        res |= (u32)(b&0x7f) << s;
        s+=7;
    }
}