"""
 * author Prasad Mahabare
 * created on 27-12-2025-11h-54m
 * github: https://github.com/MahabarePS
 * copyright 2025
"""
"""
PS: find largest and smallest number in below list:
    new_list=[1,5,7,8,-8,-4,55]
"""
new_list=[1,5,7,8,-8,-4,55]
#Store the first elements for comparision
largest = new_list[0]
smallest = new_list[0]
# iterate through the list
for i in new_list:
    if(i>largest):
        largest = i
    elif (i<smallest):
        smallest = i
print("Largest of the list: ", largest)
print("Smallest of the list: ",smallest)