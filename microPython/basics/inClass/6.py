"""
 * author Prasad Mahabare
 * created on 27-12-2025-12h-02m
 * github: https://github.com/MahabarePS
 * copyright 2025
"""
"""
PS: Remove duplicate elements from belwo list:
    rem_list=[1,1,5,6,44,8,87,45,98,44]
"""
rem_list=[1,1,5,6,44,8,87,45,98,44]
print("---list before---")
print(rem_list)
# store updated list
unique = []
# store removed elements
removed_elements = []
# using membership function
for item in rem_list:
    if item not in unique:
        unique.append(item)
    else:
        removed_elements.append(item)
print("---Updated list---")
print(unique)
print("Removed elements:")
print(removed_elements)