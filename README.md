# Vector Class
The Vector class is a simple implementation of a dynamic array in C++. It provides functionality similar to the standard library std::vector container, allowing you to store and manipulate a sequence of elements of any type.
# Usage
To use the Vector class, follow these steps:
- Include the Vector header file in your C++ source code:
 - #include "Vector.h"
- Create an instance of the Vector class by specifying the desired capacity (optional) or using the default constructor:
 - Vector<int> vec;  // Create an empty vector
 - Vector<double> vec2(10);  // Create a vector with an initial capacity of 10
Use the various member functions provided by the Vector class to manipulate the vector:
- push_back(const T&): Adds an element to the end of the vector.
- pop_back(): Removes the last element from the vector.
- at(int): Accesses the element at the specified index.
- size(): Returns the number of elements in the vector.
- clear(): Removes all elements from the vector.
- front(): Returns a reference to the first element in the vector.
- back(): Returns a reference to the last element in the vector.
- empty(): Checks if the vector is empty.
- capacity(): Returns the current capacity of the vector.
- erase(int): Removes the element at the specified index.
- insert(int, const T&): Inserts an element at the specified index.
- insert(int, int, int): Inserts multiple elements with a specific value at the specified index.
- insert(Vector*, int, int): Inserts elements from another vector into the current vector.
- operator[]: Provides array-style indexing for accessing elements.
- begin(): Returns a pointer to the first element in the vector.
- end(): Returns a pointer to the element past the last element in the vector.
