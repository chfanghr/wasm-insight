#include <datas/str.h>
#include <platform/adaptLibs.h>

void test_vector() {
    VECTOR_OF(i32) vec;
    VECTOR_INIT(vec);
    VECTOR_PUSH_BACK(vec,1);
    VECTOR_PUSH_BACK(vec,2);
    VECTOR_PUSH_BACK(vec,3);
    debug_out("%d\n",VECTOR_BACK(vec));
    VECTOR_FREE(vec);
}