#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y, z, U, w, v, f;

    // Ввод x и y и z от пользователя
    cout << "Введите значение x: ";
    cin >> x;
    cout << "Введите значение y: ";
    cin >> y;
    cout << "Введите значение z: ";
    cin >> z;

    // Вычисление f
    f = -exp(x * sqrt(abs(y))) + z;
    cout << "Значение f: " << f << endl;

    // Вычисление v (кубический корень)
    v = cbrt(abs(pow(sin(cos(f)), 2)) + x);
    cout << "Значение v: " << v << endl;
    
    // Вычисление w
    w = f + v + log10(abs(x * y * z));
    cout << "Значение w: " << w << endl;

    // Вычисление U
    U = x + y + exp(-w * v * f);

    // Вывод результата
    cout << "Значение U: " << U << endl;

    return 0;
}