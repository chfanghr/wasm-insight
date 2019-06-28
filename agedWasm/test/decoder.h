#include <decoders/decoder.h>
#include <addExample.h>
#include <importExample.h>

void test_decoder() {
    decode(addExample,sizeof_addExample);
    decode(importExample,sizeof_importExample);
}