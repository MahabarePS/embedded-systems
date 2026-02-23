/*
 * author Prasad Mahabare
 * created on 23-02-2026-23h-08m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/

/*
Is this safe?
*/
#include<stdio.h>
#include<stdint.h>
typedef struct{
    uint16_t raw_adc;
    uint16_t voltage_mv;
    uint16_t current_ma;
}ADC_result;

ADC_result* ADC_read(void){
    ADC_result result;
    return &result;
}

/*
why? 
Undefined behavior 
bz result is:
    - Local
    - On the stack
    - Destroyed when function exits
So after returning:
    The pointer points to memory that no longer belongs to you.
    A DANGLING POINTER

    Not efficient.
    Not Clever.
    Just Broken.

You may only return a pointer if:

It points to static memory

Or global memory

Or memory allocated elsewhere (heap)

Or memory owned by caller

Never to a local automatic variable.

*/

// ADVANCE

ADC_result ADC_read(void)
{
    static ADC_result result;
    return result;
}
/*
Is this:

A) Safe
B) Dangerous
C) Architecturally bad
D) All of the above

Is it memory-safe?

Yes.
static means:

Lives for entire program

Not destroyed on return

So no dangling pointer.

But is it architecturally good?

Usually ❌ No.

Why?

Because now:

Every call shares the same instance.

You cannot have two independent readings at once.

It becomes hidden global state.

Not re-entrant.

Not thread-safe.

Hard to test.

🎯 Correct Answer

D) All of the above
✔ Safe (memory-wise)
✔ Dangerous (architecturally)
✔ Bad design in most firmware cases

🧠 Why It’s Architecturally Bad

Imagine:

ADC_Result r1 = ADC_read();
ADC_Result r2 = ADC_read();

Both calls internally use the same static object.

If interrupt calls it too?
If ISR modifies it?
If you later support multiple ADC channels?

Now you have coupling.

🧠 Firmware Golden Rule

Static inside function = hidden global.

Use it only when you intentionally want:

Persistent state

Internal caching

Singleton behavior

Otherwise avoid.
*/