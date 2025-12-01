#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double i, k, m, n, b, d;

    // Ввод d и m от пользователя
    cout << "Введите значение d: ";
    cin >> d;
    cout << "Введите значение m: ";
    cin >> m;
     
    // Вычисление b (кубический корень)
    b = cbrt(pow(tan(m * d), 2));
    cout << "Значение b: " << b << endl;
    
    // Вычисление k
    k = pow(m, m * sin(b));
    cout << "Значение k: " << k << endl;

    // Вычисление n
    n = exp(d - m);
    cout << "Значение n: " << n << endl;

     // Вычисление i
    i = log10(pow(abs(m + n), 1 / k));

    // Вывод результата
    cout << "Значение i: " << i << endl;

    return 0;
}