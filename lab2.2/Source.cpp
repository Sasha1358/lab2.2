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

    cout << "Введіть значення для матриці a:\n";
    cin >> a;

    cout << "Введіть значення для матриці b:\n";
    cin >> b;

    cout << "Матриця a:\n" << a << endl;
    cout << "Матриця b:\n" << b << endl;

    Matrix sum = a + b;
    cout << "Сума матриць a і b:\n" << sum << endl;

    Matrix difference = a - b;
    cout << "Різниця матриць a і b:\n" << difference << endl;

    Matrix product = a * b;
    cout << "Добуток матриць a і b:\n" << product << endl;

    // Операції присвоєння з розширеними опціями
    a += b;
    cout << "Матриця a після операції a += b:\n" << a << endl;

    a -= b;
    cout << "Матриця a після операції a -= b:\n" << a << endl;

    a *= b;
    cout << "Матриця a після операції a *= b:\n" << a << endl;

    return 0;
}
