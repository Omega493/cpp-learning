#include <iostream>
#include <cmath>

using namespace std;

template<typename T>

class Complex {

private:

	T real;
	T imag;

public:

	static const Complex<T> Zero;

	Complex(T x = 0.0, T y = 0.0) { // Initialize complex numbers to 0 if no arguments are passed
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

		// (a + ib) / (c + id) = (ac + bd) / r + i (bc - ad) / r, where r = c^2 + d^2
		// TODO: Add checking for Z = 0.

		const T prod = Z.real * Z.real + Z.imag * Z.imag;

		return Complex(
			((real * Z.real) + (imag * Z.imag)) / prod,
			((imag * Z.real) - (real * Z.imag)) / prod
		); // Improve readability
	}

	T modulus() const {

		//If Z = a + ib, then, |Z| = sqrt(a^2 + b^2)

		return sqrt(real * real + imag * imag);
	}

	double argument() const {
		
		// If Z = x + iy, then arg(Z) = arctan(y / x)

		return atan2(imag, real);
	}

	Complex<T> conjugate() const {
		
		// If Z = a + ib, then its conjugate is a - ib

		return Complex(real, -imag);
	}

	template <typename U>
	friend ostream& operator<< (ostream& os, const Complex<U>& Z);

};

// Initialize the null complex number (0)
template<typename P>
const Complex<P> Complex<P>::Zero(0, 0);

template <typename U>
ostream& operator<< (ostream& os, const Complex<U>& Z) {
	os << "(" << Z.real << ", " << Z.imag << ")";
	return os;
}

int main() {

	Complex<double> a(2.732, 3.1415), b(1.616, 0.693), c, d, e, f;

	c = a + b;
	d = a - b;
	e = a * b;
	f = a / b;

	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;
	cout << "f = " << f << endl;

	cout << endl;

	cout << "Modulus of c = " << c.modulus() << endl;
	cout << "Conjugate of c = " << c.conjugate() << endl;
	cout << "Argument of c = " << c.argument() << endl;

	return 0;
}