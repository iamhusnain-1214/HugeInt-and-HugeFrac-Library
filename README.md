# HugeInt Library

An arbitrary precision integer and fraction library built from scratch in C++.
No external libraries. No limits on number size.

## Features

### HugeInteger
- Addition, subtraction, multiplication, division, modulus
- All comparison operators
- Pre/post increment and decrement
- Unary minus
- Digit access by index
- File I/O support
- Handles numbers of any size — thousands of digits

### HugeFraction
- Full arithmetic — add, subtract, multiply, divide
- Auto-reduces fractions using GCD (Euclidean algorithm)
- Parses decimal strings including repeating decimals e.g. 0.(3), 1.1(6)
- All comparison operators
- File I/O support

## Files
- `HugeInteger.h / .cpp` — Core big integer class
- `HugeFraction.h / .cpp` — Fraction class built on HugeInteger
- `main.cpp` — Interactive menu-driven demo
- `input.txt` — Sample huge integers
- `fractions.txt` — Sample fractions including repeating decimals

## Tech
C++ · Operator Overloading · OOP · Data Structures

## Author
Muhammad Husnain Ali — BS AI @ ITU Lahore
