/*
PS: Bits operation
*/
#include<stdio.h>
struct bitwise{
    uint8_t b0:1;
    uint8_t b1:1;
    uint8_t b2:1;
    uint8_t b3:1;
    uint8_t b4:1;
    uint8_t b5:1;
    uint8_t b6:1;
    uint8_t b7:1;
};
union U{
    unsigned char c;
    struct bitwise bits;
}t;
