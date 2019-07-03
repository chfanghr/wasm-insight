#include <decoders/decoder.h>
#include "../src/addExample.h"
#include "../src/importExample.h"

#include <array/array.h>
#include <string.h>

void test_decoder() {
    array addExampleArray = array_from_array(addExample,sizeof_addExample,sizeof(byte));
    decode(addExampleArray);
    //decode(importExample,sizeof_importExample);
    array_destroy(addExampleArray);
}