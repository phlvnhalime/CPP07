# C++ Module 07: Templates

This module focuses on the concept of **templates** in C++. Templates are a fundamental feature of C++ that allows for writing generic programs. By using templates, you can create functions and classes that work with any data type without code duplication.

## 📚 What are Templates?

Templates in C++ enable **generic programming** - writing code that works with multiple types without repeating the implementation. The compiler generates type-specific versions of the template code at compile time through a process called **template instantiation**.

### Key Concepts:
- **Function Templates**: Generic functions that work with any type
- **Class Templates**: Generic classes that can work with different types
- **Template Instantiation**: The compiler creates specific versions for each type used
- **Type Safety**: Templates maintain type safety at compile time
- **Code Reusability**: Write once, use with many types

## 🏗️ Project Structure

```
CPP07/
├── ex00/              # Basic function templates (swap, min, max)
│   ├── main.cpp
│   ├── whatever.hpp
│   └── Makefile
├── ex01/              # Function template with function pointers
│   ├── main.cpp
│   ├── iter.hpp
│   └── Makefile
├── ex02/              # Class template for dynamic Array
│   ├── main.cpp
│   ├── Array.hpp
│   └── Makefile
└── README.md
```

## 📝 Exercises

### Exercise 00: Basic Function Templates

**Goal**: Implement basic function templates for common operations.

**Functions to implement:**
- `swap(T& a, T& b)`: Swaps two values of any type
- `min(const T& a, const T& b)`: Returns the minimum of two values
- `max(const T& a, const T& b)`: Returns the maximum of two values

**Key Learning Points:**
- Basic template syntax: `template <typename T>`
- Template functions can work with any type that supports the required operations
- `min` and `max` require the type to have `<` and `>` operators

**Example Usage:**
```cpp
int a = 2, b = 3;
::swap(a, b);  // a = 3, b = 2
int m = ::min(a, b);  // m = 2
int M = ::max(a, b);  // M = 3

std::string c = "chaine1", d = "chaine2";
::swap(c, d);  // Works with strings too!
```

---

### Exercise 01: Function Template with Function Pointers

**Goal**: Create a template function `iter` that applies a function to each element of an array.

**Function to implement:**
- `iter(T* array, size_t length, void (*func)(T&))`: Iterates over an array and applies a function to each element

**Key Learning Points:**
- Template functions can accept function pointers
- Const overloads for const arrays and const functions
- Generic iteration pattern

**Example Usage:**
```cpp
int array[] = {1, 2, 3, 4, 5};
iter(array, 5, print_element);  // Prints each element

std::string arr[] = {"Hello", "World"};
iter(arr, 2, print_element);  // Works with any type!
```

---

### Exercise 02: Class Template - Dynamic Array

**Goal**: Implement a class template `Array` that behaves like a standard array but with bounds checking.

**Requirements:**
- **Template class** `Array<T>` that works with any type `T`
- **Constructors**:
  - Default constructor: Creates empty array
  - Parameterized constructor: `Array(unsigned int n)` - creates array of size `n`
  - Copy constructor: Deep copy implementation
- **Destructor**: Properly frees allocated memory
- **Assignment operator**: Deep copy with proper memory cleanup
- **Subscript operator `[]`**: 
  - Both non-const and const versions
  - **Throws `std::exception` if index is out of bounds**
- **Size method**: Returns the size of the array

**Key Learning Points:**
- **Template class syntax**: `template <typename T> class Array`
- **Template implementations must be in header files** (compiler needs full definition)
- **Exception handling**: `std::out_of_range` for invalid indices
- **Deep copy**: Copy constructor and assignment operator must create independent copies
- **Memory management**: Proper `new[]`/`delete[]` usage

**Important Notes:**
- Template class member functions **must** be implemented in the header file (`.hpp`)
- When accessing elements with `[]`, if index is out of bounds, an exception must be thrown
- The array must perform **deep copies**, not shallow copies

**Example Usage:**
```cpp
Array<int> numbers(5);
numbers[0] = 42;        // Valid access
int value = numbers[0]; // Valid read

// Exception handling
try {
    numbers[10] = 0;    // Out of bounds - throws exception
}
catch(const std::exception& e) {
    std::cout << e.what() << std::endl;
}

// Deep copy
Array<int> copy = numbers;  // Independent copy
```

## 🛠️ Compilation

Each exercise has its own `Makefile`. To compile and run:

```bash
# Exercise 00
cd ex00
make
./whatever

# Exercise 01
cd ex01
make
./iter

# Exercise 02
cd ex02
make
./array
```

Or compile manually:
```bash
c++ -Wall -Wextra -Werror -std=c++11 main.cpp -o program
```

## 🧪 Testing

For Exercise 02, you should test with memory checkers:

**On macOS:**
```bash
# Using AddressSanitizer
c++ -fsanitize=address -g -O0 main.cpp -o array_test
./array_test

# Using leaks
leaks --atExit -- ./array
```

**On Linux (42 school):**
```bash
# Using Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./array
```

## 📖 Key Template Concepts

### Function Templates
```cpp
template <typename T>
T functionName(T parameter) {
    // Implementation
}
```

### Class Templates
```cpp
template <typename T>
class ClassName {
    // Class definition
};

// Implementation must be in header:
template <typename T>
ClassName<T>::functionName() {
    // Implementation
}
```

### Why Templates?
- **Code Reusability**: Write once, use with many types
- **Type Safety**: Compile-time type checking
- **Performance**: No runtime overhead (resolved at compile time)
- **Generic Algorithms**: Write generic code that works with any compatible type

## ⚠️ Common Mistakes to Avoid

1. **Forgetting `template <typename T>` prefix** when implementing template class methods
2. **Putting template implementations in `.cpp` files** - they must be in headers!
3. **Shallow copying in copy constructor/assignment** - must do deep copy
4. **Not handling exceptions** for out-of-bounds access
5. **Memory leaks** in assignment operator - delete old array before allocating new one

## 🎯 Learning Outcomes

After completing this module, you should understand:
- ✅ How to write function templates
- ✅ How to write class templates
- ✅ Template syntax and semantics
- ✅ Why template implementations must be in header files
- ✅ How to use templates for generic programming
- ✅ Exception handling with templates
- ✅ Memory management in template classes

## 📚 References

- [cppreference.com - Templates](https://en.cppreference.com/w/cpp/language/templates)
- C++ Standard: Template instantiation
- 42 School C++ Module 07 Subject

---

**Author**: hpehliva  
**School**: 42 Heilbronn  
**Module**: C++ Module 07 - Templates

