#include "vect2.hpp"
#include <iostream>
#include <sstream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int main()
{
    vect2 v1;           // 0, 0
    vect2 v2(1, 2);     // 1, 2
    const vect2 v3(v2); // 1, 2
    vect2 v4 = v2;      // 1, 2

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;

    std::cout << GREEN << "-----INCREMENT SECTION----" << RESET << std::endl;
    std::cout << v4++ << std::endl; // 2, 3
    std::cout << "v4: " << v4 << std::endl;
    std::cout << ++v4 << std::endl; // 3, 4
    std::cout << "v4: " << v4 << std::endl;
    std::cout << RED << "-----DECREMENT SECTION----" << RESET << std::endl;
    std::cout << v4-- << std::endl; // 2, 3
    std::cout << "v4: " << v4 << std::endl;
    std::cout << --v4 << std::endl; // 1, 2
    std::cout << "v4: " << v4 << std::endl;
    std::cout << std::endl;

    vect2 v5 = (v2 += v3); // 2, 4
    std::cout << GREEN << "v5: v2 += v3 => " << RESET << v5 << std::endl;
    vect2 v6 = (v1 -= v2); // -2, -4
    std::cout << RED << "v6: v1 -= v2 => " << RESET << v6 << std::endl;
    std::cout << std::endl;

    vect2 v7 = (v2 = v3 + v3 * 2); // 3, 6
    std::cout << GREEN << "v7: (v2 = v3 + v3 * 2) => " << RESET << v7 << std::endl;
    vect2 v8 = (v2 = 3 * v2); // 9, 18
    std::cout << RED << "v8: (v2 = 3 * v2) => " << RESET << v8 << std::endl;
    vect2 v9 = (v2 += v2 += v3); // 20, 40
    std::cout << GREEN << "v9: (v2 += v2 += v3) => " << RESET << v9 << std::endl;
    vect2 v10 = (v1 *= 42); // -84, -168
    std::cout << RED << "v10: (v1 *= 42) => " << RESET << v10 << std::endl;
    vect2 v11 = (v1 = v1 - v1 + v1); // -84, -168
    std::cout << GREEN << "v11: (v1 = v1 - v1 + v1) => " << RESET << v11 << std::endl;
    std::cout << std::endl;

    std::cout << RED << "v1: " << RESET << v1 << std::endl;
    std::cout << GREEN << "v2: " << RESET << v2 << std::endl;
    std::cout << RED << "-v2: " << RESET << -v2 << std::endl;
    std::cout << std::endl;
    std::cout << GREEN << "v1[1]: " << RESET << v1[1] << std::endl;
    (v1[1] = 12);
    std::cout << RED << "v1[1] => (v1[1] = 12): " << RESET << v1[1] << std::endl;
    std::cout << GREEN << "v3[1]: " << RESET << v3[1] << std::endl;
    std::cout << std::endl;

    std::cout << RED << "-----== && != SECTION----" << RESET << std::endl;
    std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
    std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
    std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
    std::cout << "v1 != v1: " << (v1 != v1) << std::endl;

    return 0;
}
