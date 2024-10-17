## 
<h1><img src="https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/covers/cover-cpp-bonus.png"</h1>

## Description
This project consists of implementing a C++ class following the canonical form of Coplien, which includes a default constructor, copy constructor, assignment operator, and destructor. The goal is to create a Fixed class representing fixed-point numbers, with a fixed precision of 8 bits for the fractional part.

## Exercise 00 - My First Canon
Objectives 🚀:
- This exercise introduces you to the canonical form of Coplien in C++.
- You will create a class that represents a fixed-point number with 8 bits of fractional precision.

Requirement:
- Create a class named `Fixed` that adheres to the canonical form of Coplien (default constructor, copy constructor, assignment operator, and destructor).
- Add the following private member: an integer to store the fixed-point number's value - a static constant integer representing the number of bits (always 8) used for the fractional part.
- Public member functions: a `getRawBits()` function that returns the raw value of the fixed-point number - a `setRawBits(int const raw)` function to set the raw value.
- In the `main` function, create instances of `Fixed`, copy them, assign values, and print the results using `getRawBits()`.

## Exercise 01 - First Steps Toward a Useful Class
Objectives 🚀:
- This exercise builds on the previous one by adding constructors for converting integers and floating-point numbers to fixed-point representation.

Requirements:
- Extend the `Fixed` class by adding: a constructor that takes an integer and converts it to fixed-point - a constructor that takes a floating-point number and converts it to fixed-point - a `toFloat()` member function to convert the fixed-point number to a floating-point number - a `toInt()` member function to convert the fixed-point number to an integer.
- Overload the output stream operator (`<<`) to print the fixed-point number in floating-point format.
- Test these features in the `main` function by creating `Fixed` instances from integers and floating-point numbers, then print their values and conversions.

## Exercise 02 - Now We Can Talk
Objectives 🚀:
- This exercise explores operator overloading to perform arithmetic and comparison operations with fixed-point numbers.

Requirements:
- Overload the following operators for the `Fixed` class: Comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=` - Arithmetic operators: `+`, `-`, `*`, `/` - Increment/decrement operators: `++`, `--` (both prefix and postfix).
- Add static member functions `min()` and `max()` to return the smaller or larger of two `Fixed` objects.
- Test each functionality in the `main` function to ensure proper behavior.

## Exercise 03 - BSP
Objectives 🚀:
- This exercise demonstrates how to use the `Fixed` class for practical purposes, such as determining whether a point is inside a triangle using Binary Space Partitioning (BSP).

Requirements:
- Create a Point class that represents a 2D point using Fixed coordinates.
- Add the following: Private members for `x` and `y` coordinates (as `Fixed`) - A constructor, copy constructor, assignment operator, and destructor.
- Implement the function `bool bsp(Point const a, Point const b, Point const c, Point const point)` which determines if `point` is inside the triangle formed by `a`, `b`, and `c`.
