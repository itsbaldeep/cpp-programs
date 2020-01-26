#include <iostream>

using namespace std;

class Factorial {

    private:
        int number;
        int factorial;
        int compute(int x);
        
    public:
        Factorial();
        Factorial(int n);
        void print();
        
};

int main() {
    Factorial f;
    f.print();
    return 0;
}

int Factorial::compute(int x) {
    if (x < 2) return 1;
    return x * compute(x - 1);
}

Factorial::Factorial() {
    cout << "Enter the value: ";
    cin >> number;
    factorial = compute(number);
}

Factorial::Factorial(int n) {
    number = n;
    factorial = compute(number);
}

void Factorial::print() {
    cout << "Factorial of " << number << " is: " << factorial << endl;
}
