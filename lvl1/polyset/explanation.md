# Polyset

A **bag** (or multiset) represents a collection of elements where duplicates are allowed, while a **set** is a collection that elements are mathematically structured, usually focusing on uniqueness or specific access patterns.<br>
This is achieved by using different underlying data structures like an **array** or a **Binary Search Tree (BST)** to store and search data efficiently depending on the use case.

This exercise implements searchable variants of basic bags (`searchable_array_bag` and `searchable_tree_bag`) through **multiple inheritance**, and a **[set class](https://github.com/example/polyset/blob/main/set.hpp)** that wraps a `searchable_bag` abstract instance, handling data manipulation through delegation.

### Implementation of `set.cpp`

The `set` class is implemented using the **Wrapper design pattern**. Instead of managing memory or implementing a search algorithm directly, it delegates all its responsibilities to an underlying container:

* **Reference Composition:** The class stores a reference to a `searchable_bag` (`searchable_bag &_bag;`). This allows it to work polymorphically with any class derived from it (like `searchable_array_bag` or `searchable_tree_bag`).
* **Method Delegation:** Every method in `set.cpp` (`has`, `insert`, `print`, `clear`, `get_bag`) simply routes the call directly to the internal `_bag` instance. For example, calling `set::insert(value)` internally executes `_bag.insert(value)`.
* **Const Correctness:** Functions like `print()` and `get_bag()` guarantee they won't modify the state of the class by using the `const` qualifier, respecting the Orthodox Canonical Form requirements.

#### Examples

| Object       | Operation        | Result                                   |
| ------------ | ---------------- | ---------------------------------------- |
| set(my_bag)  | .insert(42)      | Calls `my_bag.insert(42)`                |
| set(my_bag)  | .insert(arr, 5)  | Inserts an array of 5 elements into bag  |
| set(my_bag)  | .has(42)         | Returns true if 42 exists in the bag     |
| set(my_bag)  | .print()         | Prints the content of the underlying bag |
| set(my_bag)  | .clear()         | Clears all elements from the bag         |

- [x] [`searchable_array_bag.hpp`](#) - Searchable array-based bag header
- [x] [`searchable_array_bag.cpp`](#) - Searchable array-based bag source
- [x] [`searchable_tree_bag.hpp`](#) - Searchable tree-based bag header
- [x] [`searchable_tree_bag.cpp`](#) - Searchable tree-based bag source
- [x] [`set.hpp`](#) - Set class wrapper header
- [x] [`set.cpp`](#) - Set class wrapper source
