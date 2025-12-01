#include <iostream>
using namespace std;

struct complex {
    float re;
    float im;
};

complex read() {
    complex c;
    cout << "Введите действительную часть: ";
    cin >> c.re;
    cout << "Введите мнимую часть: ";
    cin >> c.im;
    return c;
}

void print(complex c) {
    cout << c.re << (c.im >= 0 ? "+" : "") << c.im << "i" << endl;
}

complex add(complex a, complex b) {
    complex result;
    result.re = a.re + b.re;
    result.im = a.im + b.im;
    return result;
}

int main() {
    cout << "Введите первое комплексное число:" << endl;
    complex c1 = read();
    
    cout << "Введите второе комплексное число:" << endl;
    complex c2 = read();

    cout << "Первое комплексное число: ";
    print(c1);
    
    cout << "Второе комплексное число: ";
    print(c2);

    complex sum = add(c1, c2);
    cout << "Сумма комплексных чисел: ";
    print(sum);

    return 0;
}