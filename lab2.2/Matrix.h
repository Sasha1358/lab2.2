// Matrix.h
#pragma once
#include <iostream>
#include <sstream>  // Include the necessary header for stringstream
using namespace std;

class Matrix {
private:
    float** data;  // вказівник на вказівник на float
    int rows;
    int cols;
    void generateRandomValues();

public:
    Matrix();  // конструктор за умовчанням
    Matrix(int r, int c);  // конструктор з одними параметрами
    Matrix(int r, int c, float** array);  // конструктор з двома параметрами
    Matrix(const Matrix& other);  // конструктор копіювання
    ~Matrix();  // деструктор

    // getters
    int getRows() const;
    int getCols() const;
    float** getData() const;

    // setters
    void setRows(int r);
    void setCols(int c);
    void setData(float** d);

    // Операції присвоєння
    Matrix& operator=(const Matrix& other);

    // Операції додавання, віднімання, множення
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    // Операції присвоєння з розширеними опціями
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);

    // Потокові операції введення-виведення
    friend ostream& operator<<(ostream& out, const Matrix& matrix);
    friend istream& operator>>(istream& in, Matrix& matrix);

    // Функція перетворення у рядок
    string to_string() const;
};
