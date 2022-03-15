# C++

Tasks from classes.

---

## Task 1

Write a class (for example named `Converter`) which will have one member of the unsigned `long` type (or: `size_t` or `size_type`). This class should have:

* Conversion operators from types `char`, `const char *`, `std::string`, which will compute "number" on the basis of char - ASCII code, character string - the sum of individual ASCII codes characters in the string and assign that value to a member
* the `>>` and `<<` operators by means of which it will be possible to load the `Converter` type object integer value, char or string, or print the value of a member to the screen (total) of this object

---

## Task 2

Write a set of classes B1, B2, B3, V1, V2, D1, D2, M1, M2 and X. In each of these classes, write a constructor and destructor that will output simply information that such an object is being built / destroyed. The classes V1 and V2 are virtually inherited. Analyze the order in which objects are created and destroyed when creating an object of type X.

---

## Task 3

Write a set of "mixed classes" CanDoResearch, CanTeach, TPerson, CanBeStudent and children, as in the diagram. In each class put at least one component method that may somehow reflect the purpose or operation of the given object class. Demonstrate the program by creating several child class objects. Also analyze the situation of the TPhDResearcher type, which type receives the TPerson class on two routes of inheritance.
