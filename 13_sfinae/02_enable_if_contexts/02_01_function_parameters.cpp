#include <type_traits>
#include <iostream>

// Redefinition problem

template <typename T, typename U = std::enable_if_t<std::is_pointer<T>::value>>
T foo(T, int)
{
    std::cout << "pointer" << std::endl;
    return T{};
}

template <typename T, typename U = std::enable_if_t<!std::is_pointer<T>::value>>
T foo(T, long)
{
    std::cout << "non-pointer" << std::endl;
    return T{};
}

int main()
{
    foo(std::true_type{}, 0);
}
