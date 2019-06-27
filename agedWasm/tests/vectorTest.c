#include <datas/vector.h>
#include <datas/types.h>
#include <platform/adaptLibs.h>

int main(){
    VECTOR_OF(i32) vec;
    VECTOR_INIT(vec);
    VECTOR_PUSH_BACK(vec,1);
    VECTOR_PUSH_BACK(vec,2);
    VECTOR_PUSH_BACK(vec,3);
    debug_out("%d\n",VECTOR_BACK(vec));
    VECTOR_FREE(vec);
    return 0;
}