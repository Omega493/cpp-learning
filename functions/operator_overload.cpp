#include <iostream>

using namespace std;

struct complex {
	double real, imag;
};

complex newComplex(double x, double y) {
	complex Z;
	Z.real = x;
	Z.imag = y;
	return Z;
}

void printComplex(complex Z) {
	cout << '(' << Z.real << ", " << Z.imag << ')' << endl;
}

static complex operator+ (complex Z1, complex Z2) {
	complex Z;
	Z.real = Z1.real + Z2.real;
	Z.imag = Z1.imag + Z2.imag;
	return Z;
}

static complex operator- (complex Z1, complex Z2) {
	complex Z;
	Z.real = Z1.real - Z2.real;
	Z.imag = Z1.imag - Z2.imag;
	return Z;
}

int main() {
	complex a, b, c, d;
	
	a = newComplex(2.0, 1.0);
	b = newComplex(1.0, 3.0);

	c = a + b;
	d = c + a - b;
	/*
	Here, without declaring the operator+ and operator-functions, C++ would've used the traditional addition/subtraction operators.
	Thus, the declaration of the said functions are crucial, as they determines how our custom datatype is meant to perform addition/subtraction.
	*/

	cout << "c = ";
	printComplex(c);

	cout << "d = ";
	printComplex(d);

	return 0;
}