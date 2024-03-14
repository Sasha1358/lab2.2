// Matrix.h
#pragma once
#include <iostream>
#include <sstream>  // Include the necessary header for stringstream
using namespace std;

class Matrix {
private:
    float** data;  // �������� �� �������� �� float
    int rows;
    int cols;
    void generateRandomValues();

public:
    Matrix();  // ����������� �� ����������
    Matrix(int r, int c);  // ����������� � ������ �����������
    Matrix(int r, int c, float** array);  // ����������� � ����� �����������
    Matrix(const Matrix& other);  // ����������� ���������
    ~Matrix();  // ����������

    // getters
    int getRows() const;
    int getCols() const;
    float** getData() const;

    // setters
    void setRows(int r);
    void setCols(int c);
    void setData(float** d);

    // �������� ���������
    Matrix& operator=(const Matrix& other);

    // �������� ���������, ��������, ��������
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    // �������� ��������� � ����������� �������
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);

    // ������� �������� ��������-���������
    friend ostream& operator<<(ostream& out, const Matrix& matrix);
    friend istream& operator>>(istream& in, Matrix& matrix);

    // ������� ������������ � �����
    string to_string() const;
};
