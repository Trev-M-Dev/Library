# stringp

A custom C++ string-processing class built on top of the standard `std::string` class.

`stringp` extends `std::string` through public inheritance and provides additional string manipulation and processing methods that are not directly available through the standard interface.

This project is also being developed as a practical C++ learning project, with a focus on classes, inheritance, constructors, references, vectors, strings, memory management, header/source separation, and algorithm implementation.

---

## Table of Contents

* [Overview](#overview)
* [Project Goals](#project-goals)
* [Features](#features)
* [Project Structure](#project-structure)
* [Class Design](#class-design)
* [Methods](#methods)

  * [`lower()`](#lower)
  * [`upper()`](#upper)
  * [`reverse()`](#reverse)
  * [`r_lower()`](#r_lower)
  * [`r_upper()`](#r_upper)
  * [`r_reverse()`](#r_reverse)
  * [`split()`](#split)
* [How It Works](#how-it-works)
* [Example Usage](#example-usage)
* [Compilation](#compilation)
* [Current Limitations](#current-limitations)
* [Future Improvements](#future-improvements)
* [What I Am Learning](#what-i-am-learning)
* [Version History](#version-history)
* [License](#license)

---

# Overview

`stringp` is a custom C++ class designed to extend the functionality of `std::string`.

The class inherits publicly from `std::string`:

```cpp
class stringp : public std::string
```

This allows a `stringp` object to retain the functionality of a normal C++ string while also providing custom methods for additional string operations.

The project currently provides functionality for:

* Converting strings to lowercase
* Converting strings to uppercase
* Reversing strings
* Creating lowercase copies
* Creating uppercase copies
* Creating reversed copies
* Splitting strings into individual tokens

---

# Project Goals

The primary goal of this project is to build a useful custom string-processing class while gaining practical experience with C++.

The project is intended to explore concepts such as:

* Classes and objects
* Object-oriented programming
* Inheritance
* Public inheritance
* Constructor inheritance
* Member functions
* Static class members
* `constexpr`
* Arrays
* `std::string`
* `std::vector`
* References
* Range-based `for` loops
* Loops and nested loops
* Conditional statements
* String manipulation
* Tokenization
* Header files
* Source files
* Include guards
* Compilation and linking
* Temporary objects
* Copying objects
* Return values
* Memory management
* Algorithm design
* Code organization

---

# Features

## Current Features

| Feature              | Method        | Description                                              | Status |
| -------------------- | ------------- | -------------------------------------------------------- | ------ |
| Lowercase conversion | `lower()`     | Converts the current string to lowercase                 | ✅      |
| Uppercase conversion | `upper()`     | Converts the current string to uppercase                 | ✅      |
| String reversal      | `reverse()`   | Reverses the current string                              | ✅      |
| Lowercase copy       | `r_lower()`   | Returns a lowercase copy without modifying the original  | ✅      |
| Uppercase copy       | `r_upper()`   | Returns an uppercase copy without modifying the original | ✅      |
| Reversed copy        | `r_reverse()` | Returns a reversed copy without modifying the original   | ✅      |
| String splitting     | `split()`     | Splits the string into tokens                            | 🚧     |

> **Status Legend**
>
> * ✅ Complete
> * 🚧 In development
> * ⚠️ Needs improvement
> * ❌ Not implemented

---

# Project Structure

The project is currently separated into a header file and implementation files.

Example structure:

```text
stringp/
│
├── stringp.hpp
├── stringp.cpp
├── main.cpp
└── README.md
```

### `stringp.hpp`

Contains:

* The `stringp` class declaration
* Inheritance declaration
* Inherited constructors
* Static class data
* Function declarations

### `stringp.cpp`

Contains the implementations of the methods declared in `stringp.hpp`.

### `main.cpp`

Used to test and demonstrate the functionality of the `stringp` class.

### `README.md`

Contains documentation for the project.

---

# Class Design

The main class is:

```cpp
class stringp : public std::string
```

This means that `stringp` publicly inherits from `std::string`.

Conceptually:

```text
             std::string
                  │
                  │ public inheritance
                  ▼
               stringp
                  │
        ┌─────────┼─────────┐
        │         │         │
      lower()   upper()   reverse()
        │         │         │
        └─────────┼─────────┘
                  │
              Custom API
```

Because `stringp` derives from `std::string`, a `stringp` object can use many of the normal operations provided by `std::string`.

The class also adds its own functionality.

---

# Constructors

The standard `std::string` constructors are inherited using:

```cpp
std::string::string;
```

This allows objects to be constructed using the normal `std::string` construction patterns.

For example:

```cpp
stringp text = "Hello World";
```

---

# Alphabet Tables

The class currently contains two static `constexpr` character arrays:

```cpp
static constexpr char alpha_Upper[26] = {
    'A','B','C','D','E','F','G','H','I','J',
    'K','L','M','N','O','P','Q','R','S','T',
    'U','V','W','X','Y','Z'
};

static constexpr char alpha_Lower[26] = {
    'a','b','c','d','e','f','g','h','i','j',
    'k','l','m','n','o','p','q','r','s','t',
    'u','v','w','x','y','z'
};
```

These arrays are used to map uppercase characters to their corresponding lowercase characters and vice versa.

For example:

```text
Uppercase: A B C D E ...
Lowercase: a b c d e ...
            ↑
       corresponding index
```

Therefore:

```text
A → a
B → b
C → c
```

and:

```text
a → A
b → B
c → C
```

---

# Methods

## `lower()`

### Purpose

Converts all uppercase alphabetic characters in the current string to lowercase.

### Example

```cpp
stringp text = "HELLO WORLD";

text.lower();
```

Result:

```text
hello world
```

### Behavior

This method modifies the existing `stringp` object.

```text
Before:

"HELLO WORLD"

      │
      ▼
   lower()

      │
      ▼

"hello world"
```

### Return Value

```cpp
void
```

The method modifies the object directly and does not return a new string.

---

# `upper()`

### Purpose

Converts all lowercase alphabetic characters in the current string to uppercase.

### Example

```cpp
stringp text = "hello world";

text.upper();
```

Result:

```text
HELLO WORLD
```

### Behavior

The original object is modified.

### Return Value

```cpp
void
```

---

# `reverse()`

### Purpose

Reverses the characters contained in the current string.

### Example

```cpp
stringp text = "Hello";

text.reverse();
```

Result:

```text
olleH
```

### Behavior

This method modifies the existing object.

```text
Before:

H e l l o

      │
      ▼
   reverse()

      │
      ▼

o l l e H
```

### Return Value

```cpp
void
```

---

# `r_lower()`

### Purpose

Creates and returns a lowercase version of the string without modifying the original object.

The `r_` prefix is used to distinguish these methods from their mutating counterparts.

### Example

```cpp
stringp text = "HELLO";

std::string result = text.r_lower();
```

After execution:

```text
text   → "HELLO"
result → "hello"
```

### Behavior

```text
Original string
      │
      ▼
   make copy
      │
      ▼
 modify copy
      │
      ▼
 return copy
```

### Return Value

```cpp
std::string
```

---

# `r_upper()`

### Purpose

Creates and returns an uppercase version of the string without modifying the original.

### Example

```cpp
stringp text = "hello";

std::string result = text.r_upper();
```

Result:

```text
text   → "hello"
result → "HELLO"
```

### Return Value

```cpp
std::string
```

---

# `r_reverse()`

### Purpose

Creates and returns a reversed version of the string without modifying the original.

### Example

```cpp
stringp text = "Hello";

std::string result = text.r_reverse();
```

Result:

```text
text   → "Hello"
result → "olleH"
```

### Return Value

```cpp
std::string
```

---

# `split()`

### Purpose

Splits the string into individual tokens based on a delimiter.

The current implementation uses a space character as the delimiter.

### Example

```cpp
stringp text = "Hello World From C++";

std::vector<std::string> tokens = text.split();
```

Result:

```text
[
    "Hello",
    "World",
    "From",
    "C++"
]
```

### Algorithm

The method processes the string one character at a time.

Conceptually:

```text
"Hello World From C++"
      │
      ▼
"Hello"
"World"
"From"
"C++"
```

A temporary string stores the characters belonging to the current token.

When a delimiter is encountered:

1. Check whether the temporary token is empty.
2. If it isn't empty, add it to the vector.
3. Clear the temporary token.
4. Continue processing the remaining characters.

### Return Value

```cpp
std::vector<std::string>
```

---

# How It Works

The project currently uses two different approaches for string manipulation.

## Mutating Methods

These methods modify the object itself:

```cpp
lower();
upper();
reverse();
```

Example:

```cpp
stringp text = "HELLO";

text.lower();
```

The original object changes:

```text
"HELLO"
   ↓
"hello"
```

---

## Non-Mutating Methods

These methods create a modified copy and return it:

```cpp
r_lower();
r_upper();
r_reverse();
```

Example:

```cpp
stringp text = "HELLO";

std::string result = text.r_lower();
```

The original remains unchanged:

```text
text
 │
 ├── "HELLO"
 │
 └── r_lower()
        │
        ▼
     "hello"
```

This distinction is intentional and allows both styles of operation.

---

# Example Usage

A simple example:

```cpp
#include <iostream>
#include <vector>
#include "stringp.hpp"

int main() {

    stringp text = "Hello World";

    std::cout << text << "\n";

    text.upper();

    std::cout << text << "\n";

    text.lower();

    std::cout << text << "\n";

    text.reverse();

    std::cout << text << "\n";

    return 0;
}
```

---

# Compilation

The project can be compiled by compiling both the implementation file and the program containing `main()`.

For example, using `g++`:

```bash
g++ main.cpp stringp.cpp -o stringp
```

Then run:

### Windows

```bash
stringp.exe
```

### Linux/macOS

```bash
./stringp
```

---

# Current Limitations

The project is still under development.

Some areas currently require improvement or further consideration.

## Character Support

The current lowercase and uppercase implementations primarily handle the 26 English alphabet characters:

```text
A-Z
a-z
```

They do not currently provide full Unicode or locale-aware case conversion.

---

## `split()` Delimiters

The current `split()` implementation uses a space character as its delimiter.

Future versions may allow the caller to specify custom delimiters.

For example:

```cpp
text.split(',');
```

or:

```cpp
text.split(" ,;");
```

---

## Reverse Implementation

The current reversal implementation uses a temporary character array.

This implementation may be improved to use standard C++ containers or standard library algorithms.

---

# Future Improvements

Potential future features include:

* [ ] Custom delimiters for `split()`
* [ ] Multiple delimiter support
* [ ] `strip()` / whitespace removal
* [ ] `lstrip()`
* [ ] `rstrip()`
* [ ] `contains()`
* [ ] `starts_with()`
* [ ] `ends_with()`
* [ ] `replace()`
* [ ] `count()`
* [ ] `find_all()`
* [ ] `capitalize()`
* [ ] `swapcase()`
* [ ] `is_alpha()`
* [ ] `is_digit()`
* [ ] `is_alphanumeric()`
* [ ] `join()`
* [ ] More efficient case conversion
* [ ] Improved memory management
* [ ] Exception handling
* [ ] Unit tests
* [ ] Documentation for every public method
* [ ] Better API design
* [ ] Method chaining support
* [ ] Additional constructors
* [ ] Additional operators
* [ ] Performance benchmarking

> Add new ideas to this list as the project evolves.

---

# What I Am Learning

This project is being used to practice and understand C++ concepts through implementation rather than only theoretical exercises.

## C++ Concepts

* Classes
* Objects
* Inheritance
* Encapsulation
* Member functions
* Constructors
* Constructor inheritance
* Static members
* `constexpr`
* Arrays
* References
* Pointers
* Strings
* Vectors
* Iteration
* Range-based `for` loops
* Function return values
* Object copying

## Memory and Resource Management

* Stack memory
* Dynamic memory
* Object lifetime
* Temporary objects
* Copying
* References
* RAII
* Standard library containers

## Project Organization

* Header files
* Source files
* Include guards
* Compilation
* Linking
* Separating declarations from definitions
* Multi-file C++ projects

## Algorithms

* Character mapping
* String traversal
* String reversal
* Tokenization
* Temporary storage
* Iterative processing

---

# Development Philosophy

The project is intentionally being developed incrementally.

Rather than immediately relying on existing library functions, many operations are implemented manually to understand how the underlying algorithms work.

For example, lowercase conversion is implemented by comparing characters against an alphabet table rather than immediately using a library function.

This allows the project to serve both as:

1. A custom string utility class.
2. A practical C++ learning project.

As the project becomes more mature, manually implemented algorithms can be compared against standard-library implementations for correctness, readability, efficiency, and maintainability.

---

# Version History

## v0.1.0

Initial development version.

### Added

* `stringp` class
* Public inheritance from `std::string`
* Inherited `std::string` constructors
* Uppercase alphabet table
* Lowercase alphabet table
* `lower()`
* `upper()`
* `reverse()`

---

## v0.2.0

### Added

* `r_lower()`
* `r_upper()`
* `r_reverse()`
* Initial `split()` implementation

### Planned

* Improve `split()`
* Improve reverse implementation
* Add more string-processing functionality

---

## Future Versions

Use this section to document future releases.

Example:

```text
v0.3.0
- Added custom split delimiters
- Added contains()
- Added replace()

v0.4.0
- Added unit tests
- Improved internal algorithms

v1.0.0
- Stable public API
- Complete documentation
```

---

# License

Add your chosen license here.

Example:

```text
This project is licensed under the MIT License.
```

If the project is not yet licensed, replace this section with:

```text
License: Not yet specified.
```

---

# Author

**[Your Name]**

C++ learning and development project.

---

# Project Status

**Current Status:** 🚧 Active Development

This project is continuously being expanded as new C++ concepts are learned and implemented.

The README should be updated whenever:

* A new method is added
* A method is changed
* A bug is fixed
* The class design changes
* A new dependency is introduced
* The compilation process changes
* A new version is released
* A significant C++ concept is explored
