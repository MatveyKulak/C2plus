/*Задача 2. Решить задачу (своего варианта) создав функцию и еще две функции
перегружающие первую. Продемонстрировать их работу и дать ответ на вопрос:
что такое перегрузка функций и в каких случаях функции являются
перегруженными:*/
#include <iostream>
using namespace std;

int process(int x) {
    if (x % 2 == 0) {
        return x / 2; 
    } else {
        return 0;
    }
}

short process(short x) {
    if (x % 2 == 0) {
        return x / 2; 
    } else {
        return 0;
    }
}

long process(long x) {
    if (x % 2 == 0) {
        return x / 2; 
    } else {
        return 0;
    }
}

int main() {
    int num1, num2, num3;

    cout << "Введите три целых числа через пробел: " << endl;
    cin >> num1 >> num2 >> num3;

    cout << "Обработка int: " << process(num1) << endl;      
    cout << "Обработка short: " << process(num2) << endl; 
    cout << "Обработка long: " << process(num3) << endl;      

    return 0;
}
