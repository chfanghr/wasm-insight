#include "magicDecoder.h"

#include <datas/types.h>
#include <datas/buffer.h>
#include <consts/nums.h>
#include <consts/codes.h>
#include <objects/magic/magicObject.h>

#include <stdio.h>
#include <stdlib.h>

magicObject_t* decodeMagic(BUFFER* buf){
    if(BUFFER_SIZE(*buf)!= sizeof_magic+sizeof(i32)){
        fputs("magic decode fail!\n", stderr);
        abort();
    }
    int i=0;
    for(i=0;i<sizeof_magic;i++){
        if(BUFFER_DATA(*buf)[i]!=magicCode[i]){
            fputs("magic check fail!\n", stderr);
            abort();
        }
    }
    i32 version;
    BUFFER_READ(*buf,sizeof_magic,&version,sizeof(i32));
    magicObject_t* magicObject = malloc(sizeof(magicObject_t));
    if(!magicObject){
        fputs("malloc fail!\n", stderr);
        abort();
    }
    magicObject->version = version;
    return magicObject;
}