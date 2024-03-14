// Matrix.cpp
#include "Matrix.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Getters and setters
int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}

float** Matrix::getData() const {
    return data;
}

void Matrix::setRows(int r) {
    rows = r;
}

void Matrix::setCols(int c) {
    cols = c;
}

void Matrix::setData(float** d) {
    data = d;
}

// Constructors
Matrix::Matrix() : data(nullptr), rows(0), cols(0) {}

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data = new float* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new float[cols];
    }
    generateRandomValues();
}

Matrix::Matrix(int r, int c, float** array) : rows(r), cols(c) {
    data = new float* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new float[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = array[i][j];
        }
    }
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new float* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new float[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

// Destructor
Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

// Operations
Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;

        rows = other.rows;
        cols = other.cols;

        data = new float* [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new float[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] += other.data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols) {
        cerr << "Error: Matrix dimensions do not match for subtraction." << endl;
        return *this;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] -= other.data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    Matrix result = *this * other;
    *this = result;
    return *this;
}

ostream& operator<<(ostream& out, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            out << matrix.data[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

istream& operator>>(istream& in, Matrix& matrix) {
    cout << "Enter the number of rows: ";
    in >> matrix.rows;
    cout << "Enter the number of columns: ";
    in >> matrix.cols;

    matrix.data = new float* [matrix.rows];
    for (int i = 0; i < matrix.rows; ++i) {
        matrix.data[i] = new float[matrix.cols];
        for (int j = 0; j < matrix.cols; ++j) {
            matrix.data[i][j] = 0;  // Initial value
        }
    }

    matrix.generateRandomValues();

    return in;
}

void Matrix::generateRandomValues() {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Generating random values
            data[i][j] = rand() % 10;
        }
    }
}

string Matrix::to_string() const {
    stringstream ss;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ss << data[i][j] << ' ';
        }
        ss << '\n';
    }

    return ss.str();
}
