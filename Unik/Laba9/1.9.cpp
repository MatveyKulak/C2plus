/*Задача 1. Написать программу, которая используя функцию вычислит и выведет на
экран в виде таблицы значения функции (своего варианта), заданной графически
на интервале от xнач. до xкон. с шагом dx. Функция принимает в качестве параметра:
x и возвращает только одно значение у. Функция вызывается повторно в цикле и
выводится на экран таблица значений. Значение радиуса R видно на рисунке
(вводить не надо!).*/
#include <iostream>
#include <cmath>
using namespace std;

double grafic(double first_x) {

    int  R=2;
    if (first_x < -6) {
        return 2;
    }
    else if (first_x >= -6 && first_x < -2) {
        return (first_x + 2) / 4;
    }
    else if (first_x >= -2 && first_x <= 0) {
        return -sqrt(pow(R, 2) - pow(first_x + 2, 2)) + 2;   
    }   
    else if (first_x > 0 && first_x <= 2){
        return sqrt(pow(R, 2) - pow(first_x , 2));
    }
    else {
        return -first_x + 2;
    }
}

int main() {
    double first_x,last_x, dx, y;

    cout << "Введите начальный х: ";
    cin >> first_x;
    cout << "Введите конечный x: ";
    cin >> last_x;
    cout << "Введите шаг: ";
    cin >> dx;
    cout << "__________________" << endl;
    for (first_x; first_x <= last_x; first_x+=dx) {
        cout << "x=" << first_x << " | y= "<<grafic(first_x)<<endl;
    }
    return 0;
}