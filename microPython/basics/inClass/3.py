"""
 * author Prasad Mahabare
 * created on 27-12-2025-10h-13m
 * github: https://github.com/MahabarePS
 * copyright 2025
"""
"""
PS: Write python script to reverse given number using
    while loop num=12345
"""
print("--------reverse string--------")
print("Enter an integer: ")
num = input() # num = "1234"
# empty list 
temp = []
# store the input in temp[] list
for i in num:
    temp.append(i)
# reverse the list
temp.reverse()
# convert list to string
temp = ''.join(temp)
# convert the string to int
num = int(temp)
print(num)