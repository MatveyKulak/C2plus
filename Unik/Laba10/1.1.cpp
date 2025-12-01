/*Задача 1. В каждом из следующих заданий, напишите один оператор, который
выполняет указанное действие. Считайте, что объявлены длинные целые value1 и
value2, переменной value1 присвоено начальное значение 200000.*/
#include <iostream>
using namespace std;

int main() {
    long* yk;
    long value1 = 200000;
    yk = &value1;
    
    cout << "Значение объекта, на который указывает yk: " << *yk << endl;
    
    long value2;
    value2 = *yk;

    cout << "Значение value2: " << value2 << endl;
    cout << "Адрес value1: " << &value1 << endl;
    cout << "Адрес, который хранится в yk: " << yk << endl; 

    return 0;
}