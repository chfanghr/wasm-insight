//
// Created by 31838 on 7/2/2019.
//

#include "array.h"

#include <string.h>
#include <errno.h>

struct internal_array {
    size_t bytes_per_item;
    int item_count;
    void *data;
};

array array_init(const int element_count, const size_t data_size) {
    struct internal_array *init;
    if (element_count < 0 || data_size == 0) {
        return NULL;
    }
    init = malloc(sizeof(struct internal_array));
    if (!init) {
        return NULL;
    }
    init->bytes_per_item = data_size;
    init->item_count = element_count;
    if (init->item_count == 0) {
        init->data = NULL;
        return init;
    }
    init->data = calloc((size_t) element_count, data_size);
    if (!init->data) {
        free(init);
        return NULL;
    }
    return init;
}

int array_size(array me) {
    return me->item_count;
}

void array_copy_to_array(void *const arr, array me) {
    if (me->item_count == 0) {
        return;
    }
    memcpy(arr, me->data, me->item_count * me->bytes_per_item);
}

void *array_get_data(array me) {
    return me->data;
}

static int array_is_illegal_input(array me, const int index) {
    return index < 0 || index >= me->item_count;
}

int array_set(array me, const int index, void *const data) {
    if (array_is_illegal_input(me, index)) {
        return -EINVAL;
    }
    memcpy((char *) me->data + index * me->bytes_per_item, data,
           me->bytes_per_item);
    return 0;
}

int array_get(void *const data, array me, const int index) {
    if (array_is_illegal_input(me, index)) {
        return -EINVAL;
    }
    memcpy(data, (char *) me->data + index * me->bytes_per_item,
           me->bytes_per_item);
    return 0;
}

array array_destroy(array me) {
    free(me->data);
    free(me);
    return NULL;
}
