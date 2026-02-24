/*
 * author Prasad Mahabare
 * created on 24-02-2026-22h-38m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
You are building firmware for PIC18F4520.

You have:

An analog temperature sensor connected to ADC.

The ADC gives a raw 10-bit value (0–1023).

That raw value must be converted to:

Temperature in Celsius

Temperature in Fahrenheit

You must:

Read ADC value

Convert to Celsius

Convert to Fahrenheit

Provide the result to the application layer

🔎 Requirements

The application layer should not know about ADC raw values.

Clean separation between hardware layer and logic layer.

No global variables allowed.

Assume single sensor for now.

🎯 Your Task

Design:

Any structs (if needed)

Function prototypes

Return types

Parameter types

Decide whether to return struct or use pointer

Decide if const is needed

Decide ownership

📌 Important

Do NOT write full implementation.

Only write:

typedef (if needed)

function declarations

1–2 line explanation per function:

Why this return type?

Why pointer or not?

Why struct or not?

🧠 Think Before Writing

Ask yourself:

Is temperature result one logical object?

Is ADC read part of driver layer?

Should conversion be separate?

Who owns what?

*/
#include<stdio.h>
#include<stdint.h>
//logical grouping of conversion in structure
typedef struct{
    int temp_in_Celsius;
    int temp_in_Farenheit;
}Temperature;

int main(void){
    Temperature sensor;
    //store the ADC value in a variable to pass it for conversion
    int adc_val = read_ADC();
    //calculate the tem in celsius and store in struct member
    sensor.temp_in_Celsius = ADC_to_Celsius(adc_val);
    //calculate the tem in Farenheit and store in struct member
    sensor.temp_in_Farenheit = ADC_to_Farenheit(adc_val);
    return 0;
}