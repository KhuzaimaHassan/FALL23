#include <iostream>
using namespace std;

class matrix {
    int **p;
    int r;
    int c;
    int *rowmajor;
    int *multiply1D;

public:
    matrix(int row, int col);
    void input2D();
    void disp2D();
    void dispRowMajor();
    void Multiply_rowMajor(matrix &x);
    void rowMajor_2D();
    ~matrix();
};

matrix::matrix(int row, int col) {
    r = row;
    c = col;
    p = new int *[r];
    for (int i = 0; i < r; i++) {
        p[i] = new int[c];
    }
    rowmajor = new int[r * c];
}

void matrix::input2D() {
    cout << "Enter elements for " << r << "x" << c << " matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> p[i][j];
        }
    }
}

void matrix::disp2D() {
    cout << "2D Matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix::dispRowMajor() {
    cout << "Row Major Order Matrix:" << endl;
    int k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            rowmajor[k++] = p[i][j];
            cout << p[i][j] << " ";
        }
    }
    cout << endl;
}

void matrix::Multiply_rowMajor(matrix &x) {
    multiply1D = new int[r * x.c];
    int k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < x.c; j++) {
            int sum = 0;
            for (int l = 0; l < c; l++) {
                sum += rowmajor[i * c + l] * x.rowmajor[l * x.c + j];
            }
            multiply1D[k++] = sum;
        }
    }
}

void matrix::rowMajor_2D() {
    cout << "Resultant 2D Matrix:" << endl;
    int **resultant = new int *[r];
    for (int i = 0; i < r; i++) {
        resultant[i] = new int[c];
        for (int j = 0; j < c; j++) {
            resultant[i][j] = multiply1D[i * c + j];
            cout << resultant[i][j] << " ";
        }
        cout << endl;
    }
}

matrix::~matrix() {
    for (int i = 0; i < r; i++) {
        delete[] p[i];
    }
    delete[] p;
    delete[] rowmajor;
    delete[] multiply1D;
}

int main() {
    int row1, col1, row2, col2;
    cout << "Enter the number of rows and columns for the first matrix:" << endl;
    cin >> row1 >> col1;
    matrix a(row1, col1);
    a.input2D();

    cout << "Enter the number of rows and columns for the second matrix:" << endl;
    cin >> row2 >> col2;
    matrix b(row2, col2);
    b.input2D();

    a.disp2D();
    a.dispRowMajor();
    b.disp2D();
    b.dispRowMajor();
    a.Multiply_rowMajor(b);
    a.rowMajor_2D();
    return 0;
}
