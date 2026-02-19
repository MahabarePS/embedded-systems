/*
 * author Prasad Mahabare
 * created on 19-02-2026-22h-20m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
Here is the purely abstract system:

Every 20ms:

Get a raw input value (integer)
Transform it into another value
Decide a level (LOW, MEDIUM, HIGH)
Apply the level

Imagine:

Input:  123
Transform → 456
Decision → MEDIUM
Apply → Some output

You are only designing the flow structure.

Design:

get_input()
transform()
decide_level()
apply_action()

With:

Proper return types
Proper parameters
No unnecessary pointers

Clean main()
*/
#include<stdio.h>
#include<stdint.h>

int main(void)
{
    while (1)
    {
        uint16_t input = get_input();
        uint16_t transformed = transform(input);
        uint8_t level = decide_level(transformed);
        apply_action(level);
    }

    return 0;
}

