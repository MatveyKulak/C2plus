/*Задача 4. По вариантам:
4.9 Составить функцию void zamena(int &n) которая в исходном n-значном
числе оставит в этом числе только первую цифру, а остальные заменить
нулями.*/
#include <iostream>
#include <cmath>
using namespace std;

void zamena(int &n) {
    int temp = 1;
    if (n < 0) {
        temp = -1;
        n = -n;
    }

    int firstnum = n;
    while (firstnum >= 10) {
        firstnum /= 10;
    }

    int clear = 1;
    while (n >= 10) {
        clear *= 10;
        n /= 10; 
    }

    n = firstnum * clear;

    if (temp < 0) {
        n = -n;
    }
}

int main() {
    int number = 75678626;
    zamena(number);
    cout << "Новое число: " << number << endl;

    return 0;
}