// Source.cpp
#include <iostream>
#include "Matrix.h"
#include <Windows.h>
using namespace std;

string to_string(const Matrix& matrix);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Matrix a(3, 3);
    Matrix b(3, 3);

    cout << "������ �������� ��� ������� a:\n";
    cin >> a;

    cout << "������ �������� ��� ������� b:\n";
    cin >> b;

    cout << "������� a:\n" << a << endl;
    cout << "������� b:\n" << b << endl;

    Matrix sum = a + b;
    cout << "���� ������� a � b:\n" << sum << endl;

    Matrix difference = a - b;
    cout << "г����� ������� a � b:\n" << difference << endl;

    Matrix product = a * b;
    cout << "������� ������� a � b:\n" << product << endl;

    // �������� ��������� � ����������� �������
    a += b;
    cout << "������� a ���� �������� a += b:\n" << a << endl;

    a -= b;
    cout << "������� a ���� �������� a -= b:\n" << a << endl;

    a *= b;
    cout << "������� a ���� �������� a *= b:\n" << a << endl;

    return 0;
}
