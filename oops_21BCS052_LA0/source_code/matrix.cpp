#include <iostream>
using namespace std;

class Matrix {
   private:
    int matrix[10][10] = {{0}};
    int _row, _col;

   public:
    Matrix() {}
    Matrix(int r, int c) : _row(r), _col(c) {}

    void createMatrix();
    void createIdentityMatrix();
    void printMatrix();
    Matrix multiply(const Matrix &);
};

void Matrix::createMatrix() {
    int row = _row, col = _col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }
}

void Matrix::createIdentityMatrix() {
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            matrix[i][j] = (i == j) ? 1 : 0;
        }
    }
}

void Matrix::printMatrix() {
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::multiply(const Matrix &m2) {
    if (_col != m2._row) {
        cout << "Multiplication not possible.\n" << endl;
        return {};
    }
    Matrix result(_row, m2._col);
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < m2._col; j++) {
            for (int k = 0; k < _col; k++) {
                result.matrix[i][j] += matrix[i][k] * m2.matrix[k][j];
            }
        }
    }

    return result;
}

int main() {
    cout << __FILE__ << endl;
    int test_case = 1;
    cin >> test_case;
    while (test_case--) {
        int row, col;
        cout << "Enter the number of rows for Matrix m1: \n";
        cin >> row;
        cout << row << endl;
        cout << "Enter the number of columns for Matrix m1: \n";
        cin >> col;
        cout << col << endl;
        Matrix m1(row, col);
        m1.createMatrix();
        cout << "MATRIX 1:" << endl;
        m1.printMatrix();
        cout << endl;
        cout << "Enter the number of rows for Matrix m2: \n";
        cin >> row;
        cout << row << endl;
        cout << "Enter the number of columns for Matrix m2: \n";
        cin >> col;
        cout << col << endl;
        Matrix m2(row, col);
        m2.createMatrix();
        cout << "MATRIX 2:" << endl;
        m2.printMatrix();
        cout << endl;
        Matrix m3 = m1.multiply(m2);
        cout << "Resultant Matrix:" << endl;
        m3.printMatrix();
        cout << "------------------------------------------\n";
    }
    return 0;
}

