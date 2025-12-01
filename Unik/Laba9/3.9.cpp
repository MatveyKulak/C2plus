/*Задача 3. Написать программу, которая использует рекурсивную функцию для
решения задачи (своего варианта):*/
#include <iostream>
using namespace std;

void period(int a,int b) {
    cout << a << " ";

    if (a < b) {
        return period(a + 1, b);  
    } 
    else if (a > b) {
        return period(a - 1, b);  
    }
}

int main() {
    int a,b;

    cout << "Введите число a: ";
    cin >> a;
    cout << "Введите число b: ";
    cin >> b;

    period(a, b);

    return 0;
}