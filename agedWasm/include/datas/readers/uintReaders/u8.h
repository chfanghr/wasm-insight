//
// Created by 31838 on 6/28/2019.
//

#ifndef AGEDWASM_U8_H
#define AGEDWASM_U8_H

#include <datas/type.h>

u8 *swap_u8_array_element_in_place(u8 *arr, siz_t len, siz_t a, siz_t b);

u8 revert_u8_endian(u8 b);

u8 *revert_u8_array_endian(u8 *arr, siz_t len);


#endif //AGEDWASM_U8_H
