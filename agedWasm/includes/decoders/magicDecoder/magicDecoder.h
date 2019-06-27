#ifndef _MAGICDECODER_H
#define _MAGICDECODER_H

#include <datas/buffer.h>
#include <objects/magic/magicObject.h>

magicObject_t* decodeMagic(BUFFER* buf);

#endif