#include <iostream>

using namespace std;

// declaring a class called Complex
class Complex {
    // private members real and imaginary
    private:
        int real;
        int imag;

    // public member functions
    public:
        Complex() {} // default constructor
        Complex(int, int); // parameterized constructor

        Complex operator++(); // prefix increment
        Complex operator++(int); // postfix increment
        Complex operator--(); // prefix decrement
        Complex operator--(int); // postfix decrement
        Complex& operator=(const Complex&); // assignment operator
    
        friend Complex operator+(Complex&, Complex&); // add
        friend Complex operator-(Complex&, Complex&); // subtract

        friend ostream& operator<<(ostream&, const Complex&); // print
        friend istream& operator>>(istream&, Complex&); // get
};

Complex::Complex(int real, int imag) {
    this->real = real;
    this->imag = imag;
}

Complex Complex::operator++() {
    return Complex(++real, ++imag);
}

Complex Complex::operator++(int) {
    return Complex(++real, ++imag);
}


Complex Complex::operator--() {
    return Complex(--real, --imag);
}

Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    imag = c.imag;
    return *this;
}

Complex operator+(Complex& a, Complex& b) {
    Complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

Complex operator-(Complex& a, Complex& b) {
    Complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << 'i'<< endl;
    return os;
}

istream& operator<<(istream& is, Complex& c) {
    cout << "Enter the real part: ";
    is >> c.real;
    cout << "Enter the imaginary part: ";
    is >> c.imag;
    return is;
}

int main() {
    Complex c1;
    cin >> c1;
    c1++;
    cout << c1;
}
