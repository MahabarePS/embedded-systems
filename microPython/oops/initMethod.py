# __init__() is automatically called every time the class is being 
# create a new object
# Multiple parameters
class Person:
    # self is the reference to the current instance of the class
    # used to access properties and methods belonging to class
    def __init__(self, name, age):
        self.name = name
        self.age = age

p1 = Person("Prasad",28)
print("My name is: ",p1.name)
print("My age is : ",p1.age)
# without init(), you need to set properties manually for each object
class Person2:
    pass
p2 = Person2()
p2.name = "Prasad"
p2.age = 28
print("My name is   : ",p2.name)
print("My age is    : ",p2.age)
# 