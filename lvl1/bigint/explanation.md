# bigint

A **bignum** represents an integer of **arbitrary precision**, capable of storing values larger than `SIZE_MAX` or `UINT64_MAX` without loss of precision when speed does.<br>
This is achieved by storing the number’s digits as a **string** (*or **array***), and performing manual arithmetic.<br>
Mostly used for when the speed of arithmetic is not a limiting factor.

This exercise implements a **[bigint class](https://github.com/flmarsou/42nice-exam05/blob/main/bigint/bigint.hpp)** that stores an unsigned integer as a string handling **additions**, **digit shifts**, and **comparisons** through operators.

#### Examples

| Object      | Operation     | Result |
| ----------- | ------------- | ------ |
| bigint(21)  | + 21          | 42     |
| bigint(21)  | += bigint(21) | 42     |
| bigint(0)   | ++x           | 1      |
| bigint(0)   | x++           | 0 -> 1 |
| bigint(42)  | << 3          | 42000  |
| bigint(4)   | (x << 2) + 3  | 403    |
| bigint(0)   | (x << 2)      | 0      |
| bigint(0)   | (x << 2) + 3  | 3      |
| bigint(999) | >>= bigint(1) | 99     |
| bigint(999) | >>= bigint(2) | 9      |
| bigint(1)   | == bigint(1)  | true   |
| bigint(1)   | >= bigint(1)  | true   |
| bigint(9)   | < bigint(1)   | false  |

# Implementation
* **Data Storage:** The class wraps a `std::string _big` where each character represents a single numerical digit (e.g., the number `42` is stored internally as `"42"`).
* **`bigint(unsigned int nbr)`:** Initializes the object by converting an integer into its string representation using `std::to_string()`. It defaults to `0`.
* **`bigint(const bigint &other)`:** Standard copy constructor that copies the underlying string from another instance.

### Addition (`+=` and `+`)
The core arithmetic logic resides within the `operator+=` method:
* **Manual Column Addition:** It uses two pointers/indices (`i` and `j`) starting from the end of both strings (the least significant digits) and moves backward.
* **Character-to-Integer Conversion:** Characters are converted to their actual numerical value by subtracting the ASCII offset of `'0'` (e.g., `'5' - '0' = 5`).
* **Carry Management:** In each iteration, it computes `sum = digit_x + digit_y + carry`. The new carry is determined via `sum / 10`, and the single digit `sum % 10` is appended to a result string.
* **Reversal:** Because digits are processed from right to left, `std::reverse()` is applied to the final result string before updating `_big`.

### Base-10 Shifts (`<<` and `>>`)
Although these reuse bitwise shift operators, they simulate arithmetic shifting **in base-10**:
* **`<<=` (Left Shift):** Appends a specified `amount` of `'0'` characters to the end of the string (unless the value is already `"0"`). This effectively multiplies the number by $10^{\text{amount}}$.
* **`>>=` (Right Shift):** Converts the `other` bigint into a standard `unsigned long` integer using `std::atol()`. It then truncates the last $N$ digits of the string using `_big.erase()`. If the shift amount exceeds the string's length, the value resets to `"0"`.

### Increments (`++` Prefix and Postfix)
* Both operators increment the current value by creating a temporary `bigint dummy(1)` and utilizing the `+=` operator (`*this += dummy;`).
* **Prefix (`++x`):** Modifies the object's value in place and returns a reference to itself (`*this`).
* **Postfix (`x++`):** Creates a clone of the current state (`tmp`), increments the actual object, and returns the unmodified clone by value.

### Comparison Operators (`<`, `>`, `==`, etc.)
To optimize evaluations, comparison is split into two phases:
* **Length Check:** Since all numbers are positive, if two numbers have different string lengths, the one with more characters is automatically greater (e.g., `"100"` is instantly larger than `"99"` without comparing digits).
* **Lexicographical Check:** If lengths are equal, a standard alphabetical string comparison (`_big < other._big`) evaluates the numbers correctly.
* The remaining operators (`>`, `<=`, `>=`, `!=`) are logically derived as shortcuts from `<` and `==`.

* **`getBig()`:** A constant member function that exposes the internal string representation securely.
* **`operator<<` (Ostream):** Overloads the insertion stream operator to print the `bigint` directly via `std::cout` by retrieving its inner string contents.
* 
- [x] [`bigint.hpp`](https://github.com/flmarsou/42nice-exam05/blob/main/bigint/bigint.hpp) - Header file
- [x] [`bigint.cpp`](https://github.com/flmarsou/42nice-exam05/blob/main/bigint/bigint.cpp) - Code file
- [x] [`bigint_commented.cpp`](https://github.com/flmarsou/42nice-exam05/blob/main/bigint/bigint_commented.cpp) - Code file (with explanations)
- [x] [`main.cpp`](https://github.com/flmarsou/42nice-exam05/blob/main/bigint/main.cpp) - Given main with debug couts
