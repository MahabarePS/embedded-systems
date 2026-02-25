/*
 * author Prasad Mahabare
 * created on 25-02-2026-22h-38m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
STAGE 1 PROBLEM — Voltage Divider Module
🎯 Objective

Simulate a voltage divider circuit in pure C.

Hardware Concept

A voltage divider using two resistors:

𝑉
𝑜
𝑢
𝑡
=
𝑉
𝑖
𝑛
×
𝑅
2
𝑅
1
+
𝑅
2
V
out
	​

=V
in
	​

×
R1+R2
R2
	​

📌 Your Task

Design a clean, modular C program that:

1️⃣ Models a voltage divider as a structure

It must contain:

R1

R2

Vin

2️⃣ Provides clean functions:

Initialize the divider

Calculate Vout

Validate input values (no divide-by-zero)

Print results

3️⃣ Architectural Rules

You must:

Separate calculation from printing

Avoid global variables

Use const correctness properly

Decide: pass struct by value or pointer? (justify mentally)

No hidden coupling

main() should only orchestrate

🧩 Additional Engineering Constraints

Add:

Input impedance check (assume load is 10kΩ)

If output impedance > 10% of load, print warning

(You must research how to calculate output impedance of a divider.)

📦 Expected Architecture (High Level Only)

You decide file structure.

But mentally think like:

voltage_divider.h
voltage_divider.c
main.c

🚨 Think Like Hardware

Ask yourself before coding:

What happens if R1 = 0?

What happens if R2 = 0?

What happens if both are 0?

What happens if Vin is negative?

Who owns the divider data?

Is calculation allowed to modify struct?

*/
#include<stdio.h>
#include<stdint.h>
typedef struct{
    uint16_t r1;
    uint16_t r2;
    uint16_t Vin;
}VoltageDivider;