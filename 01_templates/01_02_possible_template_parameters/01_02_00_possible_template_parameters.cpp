// Describe possible template parameters
// Ask about chosen overloads
// Difference between class and typename before C++17

#include <iostream>
#include <array>

template <typename Type>
void foo() {
    Type t{};
    std::cout << "first " << __PRETTY_FUNCTION__ << std::endl;
}

template <int N>
void foo() {
    int arr[N];
    std::cout << "second " << __PRETTY_FUNCTION__ << std::endl;
}

template <template <typename, std::size_t> class Array>
void foo() {
    Array<int, 10> a{};
    std::cout << "third " << __PRETTY_FUNCTION__ << std::endl;
}

int main() {
    std::array<int, 3> arr; // works
    // std::array arr; // wouldn't compile
    foo<int>();
    foo<3>();
    foo<std::array>();
    foo<std::array<int, 3>>();
}
