#include <iostream>

using namespace std;

template<typename T>

class Complex {

private:
	
	T real;
	T imag;

public:
	
	Complex(T x = 0.0, T y = 0.0) { // Initialize complex numbers to 0 if no arguments are passed.
		real = x;
		imag = y;
	}
	
	// The addition and subtraction operators by defaut promote arguments to the double data type.

	Complex<T> operator+ (const Complex& Z) const {
		return Complex(real + Z.real, imag + Z.imag);
	}

	Complex<T> operator- (const Complex& Z) const {
		return Complex(real - Z.real, imag - Z.imag);
	}

	void display() const {
		cout << "(" << real << ", " << imag << ")" << endl;
	}
};

int main() {
	
	Complex<double> a(2.732, 3.1415), b(1.616, 0.693), c, d;
	
	c = a + b;
	d = a - b;

	cout << "C = ";
	c.display();

	cout << "d = ";
	d.display();

	return 0;
}