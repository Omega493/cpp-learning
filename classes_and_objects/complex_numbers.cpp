#include <iostream>

using namespace std;

template<typename T>

class Complex {

private:
	
	T real;
	T imag;

public:

	static const Complex<T> Zero;
	
	Complex(T x = 0.0, T y = 0.0) { // Initialize complex numbers to 0 if no arguments are passed.
		real = x;
		imag = y;
	}

	bool operator== (const Complex& Z) const {
		return (real == Z.real && imag == Z.imag);
	}
	bool operator!= (const Complex& Z) const {
		return !(*this == Z);
	}

	Complex<T> operator+ (const Complex& Z) const {
		return Complex(real + Z.real, imag + Z.imag);
	}

	Complex<T> operator- (const Complex& Z) const {
		return Complex(real - Z.real, imag - Z.imag);
	}

	Complex<T> operator* (const Complex& Z) const {
		
		// (a + ib) * (c + id) = (ac - bd) + i (ad + bc)
		
		return Complex((real * Z.real) - (imag * Z.imag), (real * Z.imag) + (imag * Z.real));
	}

	Complex<T> operator/ (const Complex& Z) const {
		
		// (a + ib) / (c + id) = (ac + bd) + i (bc - ad)
		// TODO: Add checking for Z = 0.
		
		const T prod = Z.real * Z.real + Z.imag * Z.imag;

		return Complex(((real * Z.real) + (imag * Z.imag)) / prod, ((imag * Z.real) - (real * Z.imag)) / prod);
	}

	void display() const {
		cout << "(" << real << ", " << imag << ")" << endl;
	}
};

int main() {
	
	Complex<double> a(2.732, 3.1415), b(1.616, 0.693), c, d, e, f;
	
	c = a + b;
	d = a - b;
	e = a * b;
	f = a / b;

	cout << "C = ";
	c.display();

	cout << "d = ";
	d.display();

	cout << "e = ";
	e.display();

	cout << "F = ";
	f.display();

	return 0;
}