#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b; 

     // Ввод a and b от пользователя
    cout << "Введите значение a: ";
    cin >> a;
    cout << "Введите значение b= a * a: ";
    cin >> b;

    // Вычисление a
    a = a * a;

    a = a * a;

    a = a * a;

    a = a * b;

    // Вывод результата
    cout << "Значение a: " << a << endl;

    return 0;
}