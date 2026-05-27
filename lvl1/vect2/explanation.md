# vect2 

The goal of this exercise is to create a simple **2D mathematical vector** class that supports basic arithmetic and comparison operations.

This exercise implements a **[vect2 class](https://github.com/flmarsou/42nice-exam05/blob/main/vect2/vect2.hpp)** that stores two integers (***x** and **y***) handling **indexing**, **arithmetics**, and **comparisons** through operators.

#### Examples

| Object        | Operation         | Result          |
| ------------- | ----------------- | --------------- |
| vect2(1, 2)   |                   | {1, 2}          |
| vect2(1, 2)   | ++vect2           | {2, 3}          |
| vect2(1, 2)   | vect2++           | {1, 2} -> {2, 3 |
| vect2(1, 2)   | + vect2(1, 2)     | {2, 4}          |
| vect2(1, 2)   | - vect2(1, 2)     | {0, 0}          |
| vect2(0, 0)   | - vect2(1, 2)     | {-1, -2}        |
| vect2(2, -3)  | * vect2(2, 2)     | {4, -6}         |
| vect2(69, 42) | == vect2(-69, 42) | false           |
| vect2(69, 42) | == vect2(69, 42)  | true            |
| vect2(69, 42) | != vect2(69, 42)  | false           |
| vect2(2, 0)   | -vect2            | {-2, 0}         |

- [x] [`vect2.hpp`](https://github.com/flmarsou/42nice-exam05/blob/main/vect2/vect2.hpp) - Header file
- [x] [`vect2.cpp`](https://github.com/flmarsou/42nice-exam05/blob/main/vect2/vect2.cpp) - Code file
- [x] [`main.cpp`](https://github.com/flmarsou/42nice-exam05/blob/main/vect2/main.cpp) - Given main with debug couts
