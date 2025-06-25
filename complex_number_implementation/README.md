# Complex Number Implementation in C++

This folder contains a templated `Complex` class written in C++. It supports basic arithmetic operations (addition, subtraction, multiplication, division), as well as modulus, argument, and conjugate.

Operator overloading has been used to allow expressions like `a + b` and `a * b`, where `a` and `b` are complex numbers.

The class is designed with type generality in mind (via templates), and is currently demonstrated using `double` as the underlying type.

### Features

- Template-based class for generic numeric types
- Overloaded operators: `+`, `-`, `*`, `/`, `==`, `!=`
- Modulus calculation: `modulus()`
- Argument (phase angle) using `atan2()`
- Complex conjugate: `conjugate()`
- Friend function for `ostream` printing

### Example Output

The `main()` function demonstrates operations on two complex numbers `a` and `b`, and prints the results of various computations.

```powershell
c = (4.348, 3.8345)
d = (1.116, 2.4485)
e = (2.23785, 6.96994)
f = (2.13215, 1.02965)

Modulus of c = 5.79728
Conjugate of c = (4.348, -3.8345)
Argument of c = 0.722724
```