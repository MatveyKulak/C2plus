/*Написать программу, которая вычислит и выведет на экран в виде
таблицы значения функции своего варианта, заданной графически на интервале
от xнач. до xкон. с шагом dx. Функция задается в виде графика. Значение радиуса R
видно на рисунке (вводить не надо!).*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double first_x,last_x, dx,  y, R=2;
    cout << "Введите начальный х: ";
    cin >> first_x;
    cout << "Введите конечный x: ";
    cin >> last_x;
    cout << "Введите шаг: ";
    cin >> dx;
    cout << "_______________" << endl;


    for (first_x; first_x <= last_x; dx) {
    if (first_x < 0) {
        cout << "x=" << first_x << " | y= ";
        cout << -0.5 * first_x << endl;
    }
    else {
         if (first_x >= 0 && first_x <= 2) {
            cout << "x= " << first_x << " | y= ";
            cout << -sqrt(pow(R, 2) - pow(first_x, 2)) + 2 << endl;
    }
        else  {
        if (first_x > 2 && first_x <= 4) {
            cout << "x= " << first_x << " | y= ";
            cout << sqrt(pow(R, 2) - pow(first_x - 2, 2)) << endl;       
    }
    else {
        cout << "x= " << first_x << " | y= ";
        cout << -first_x + 4 ;
    }}}
    first_x += 1;
    }

    return 0;
}