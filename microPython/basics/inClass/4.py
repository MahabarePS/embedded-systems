"""
 * author Prasad Mahabare
 * created on 27-12-2025-10h-14m
 * github: https://github.com/MahabarePS
 * copyright 2025
"""
"""
PS: Write python script to find factorial of number,
    Accpet input from user.
"""
print("----Factorial---")
print("Enter an integer: ")
num = int(input())
fact=1
if num < 0:
    print("factorial does not exist for -ve numbers")
elif num == 0:
    print("Factorial of 0 is 1")
else:
    while num > 0:
        fact = fact * num
        num = num - 1
    print("Factorial: ",fact)