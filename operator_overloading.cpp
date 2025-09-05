// Example of operator overloading in C++
#include <iostream>
using namespace std;


class Complex {
	double real, imag;
public:
	Complex(double r = 0, double i = 0) : real(r), imag(i) {}

	// Overload + operator
	Complex operator+(const Complex& other) const {
		return Complex(real + other.real, imag + other.imag);
	}

	// Overload - operator
	Complex operator-(const Complex& other) const {
		return Complex(real - other.real, imag - other.imag);
	}

	// Overload * operator
	Complex operator*(const Complex& other) const {
		return Complex(real * other.real - imag * other.imag,
					  real * other.imag + imag * other.real);
	}

	// Overload == operator
	bool operator==(const Complex& other) const {
		return real == other.real && imag == other.imag;
	}

	void display() const {
		cout << real << " + " << imag << "i" << endl;
	}
};


int main() {
	Complex c1(2.5, 3.5), c2(1.5, 4.5);
	Complex c3 = c1 + c2;
	Complex c4 = c1 - c2;
	Complex c5 = c1 * c2;

	cout << "c1 = "; c1.display();
	cout << "c2 = "; c2.display();
	cout << "c1 + c2 = "; c3.display();
	cout << "c1 - c2 = "; c4.display();
	cout << "c1 * c2 = "; c5.display();

	cout << "c1 == c2? " << (c1 == c2 ? "True" : "False") << endl;
	cout << "c1 == c1? " << (c1 == c1 ? "True" : "False") << endl;
	return 0;
}
