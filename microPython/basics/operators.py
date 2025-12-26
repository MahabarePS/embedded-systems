# Arithmetic : * / + -
# Assignment : += -= *= /= %= //= **= &= |= ^= >>= <<= :=walrus operator
# Comparison : == != > < >= <=
# Logical    : and or not
# Identiy    : is | is not -> to compare objects
x = ["apple", "banana"]
y = ["apple", "banana"]
z=x
print(x is z) # does point to the same object
print(x is y) # does not point to the same object
print(x==y)   # both are equal
# Membership : in | not in -> test if a sequence is presented in an object
fruits = ["apple","banana","cherry"]
print("banana" in fruits)
print("pineapple" not in fruits)
# Bitwise    : & | ^ ~ << >> 
# --------------------------------
# Operator precedence
# --------------------------------
# ()        Parantheses
# **        Exponentiation
# +x -x ~x  Unary
# * / // %  Mul Div FloorDivision Modulous
# + -       Addition Subtraction
# << >>     Bitwise left and right shifts
# &         Bitwise AND
# ^         Bitwise XOR
# |         Bitwise OR
# Comparisons, identity, and membership operator
# not       Logical NOT
# and       AND
# or        OR