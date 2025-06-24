#include <iostream>

using namespace std;

template<typename T>

class Complex {

private:
	
	T real;
	T imag;

public:
	
	Complex(T x = 0.0f, T y = 0.0f) { // Initialize complex numbers to 0 if no arguments are passed.
		real = x;
		imag = y;
	}
	
	// The addition and subtraction operators by defaut promote arguments to the double data type.

	Complex<double> operator+ (Complex Z2) {
		Complex<double> Z;
		Z.real = real + Z2.real;
		Z.imag = imag + Z2.imag;
		return Z;
	}

	Complex<double> operator- (Complex Z2) {
		Complex<double> Z;
		Z.real = real - Z2.real;
		Z.imag = imag - Z2.imag;
		return Z;
	}

	void display() {
		cout << "(" << real << ", " << imag << ")" << endl;
	}
};

int main() {
	
	Complex<double> a(2.732f, 3.1415f), b(1.616f, 0.693f), c, d;
	
	c = a + b;
	d = a - b;

	cout << "C = ";
	c.display();

	cout << "d = ";
	d.display();

	return 0;
}