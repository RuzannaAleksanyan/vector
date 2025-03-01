#include <iostream>
#include "vector.hpp"

int main()
{
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    std::cout << "Vector: " << vec << std::endl;

    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    std::cout << "Element at index 1: " << vec.at(1) << std::endl;
    std::cout << "Element at index 2: " << vec[2] << std::endl;

    std::cout << "Front element: " << vec.front() << std::endl;
    std::cout << "Back element: " << vec.back() << std::endl;

    vec.insert(1, 10);
    std::cout << "After inserting 10 at index 1: " << vec << std::endl;

    vec.erase(2);
    std::cout << "After erasing element at index 2: " << vec << std::endl;

    vec.clear();
    std::cout << "Vector is empty: " << (vec.empty() ? "true" : "false") << std::endl;

    vec.reserve(5);
    std::cout << "After reserving capacity of 5: " << vec << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    // Test resize
    vec.resize();
    std::cout << "After resizing: " << vec << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    Vector<int> vec2 = {4, 5, 6};
    Vector<int> vec3(vec2);
    Vector<int> vec4;
    vec4 = vec2;
    std::cout << "Vector 2: " << vec2 << std::endl;
    std::cout << "Vector 3 (copy of Vector 2): " << vec3 << std::endl;
    std::cout << "Vector 4 (assigned from Vector 2): " << vec4 << std::endl;

    std::cout << "Elements in Vector 2: ";
    for (auto it = vec2.begin(); it != vec2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    Vector<int> vec_it = {1, 2, 3, 4, 5};

    for (Vector<int>::Iterator it = vec_it.begin(); it != vec_it.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}