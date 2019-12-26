#include <iostream>
#define MAX 10

using namespace std;

class Matrix {
    private:
        int rows;
        int cols;
        int data[MAX][MAX];

    public:
        friend Matrix operator+(Matrix&, Matrix&);
        friend Matrix operator-(Matrix&, Matrix&);

        friend istream& operator>>(istream&, Matrix&);
        friend ostream& operator<<(ostream&, Matrix&);
};

istream& operator>>(istream& is, Matrix& m) {
    cout << "Rows: ";
    is >> m.rows;
    cout << "Columns: ";
    is >> m.cols;

    if (m.rows > MAX || m.cols > MAX) {
        cout << "Too big!" << endl;
        exit(0);
    }

    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            cout << "Enter data at [" << i << "][" << j << "]: ";
            is >> m.data[i][j];
        }
    }
    return is;
}

ostream& operator<<(ostream& os, Matrix& m) {
    os << endl;
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            os << m.data[i][j] << " ";
        } os << endl;
    } os << endl;
    return os;
}

Matrix operator+(Matrix& a, Matrix& b) {
    Matrix c;
    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Wrong size";
        exit(0);
    }

    c.rows = a.rows;
    c.cols = a.cols;
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }

    return c;
}

Matrix operator-(Matrix& a, Matrix& b) {
    Matrix c;
    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Wrong size";
        exit(0);
    }

    c.rows = a.rows;
    c.cols = a.cols;
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            c.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }

    return c;
}

int main() {
    Matrix a, b;
    cin >> a;
    cin >> b;
    cout << "Matrix A: " << a;
    cout << "Matrix B: " << b;

    Matrix c = a + b;
    cout << "A + B: " << c;
    Matrix d = a - b;
    cout << "A - B: " << d;
}
