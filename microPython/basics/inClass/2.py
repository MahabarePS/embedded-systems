"""
 * author Prasad Mahabare
 * created on 27-12-2025-10h-12m
 * github: https://github.com/MahabarePS
 * copyright 2025
"""
"""
PS: Write a python script to print all prime,
numbers from 1 to 100
"""
def is_prime(n):
    """Checks if a number is a prime number."""
    # Prime numbers must be positive integers greater than 1.
    if n <= 1:
        return False
    # Check for factors from 2 up to the square root of n.
    # If a factor is found, the number is not prime.
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    # If no factors are found, the number is prime.
    return True

# Iterate through numbers from 1 to 100
print("Prime numbers from 1 to 100 are:")
for number in range(1, 101):
    if is_prime(number):
        print(number, end=" ")
