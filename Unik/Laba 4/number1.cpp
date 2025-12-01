#include <iostream>

using namespace std;

int main() {
    int a;

    cout << "Введите a: ";
    cin >> a;

    if (a < -999 || a > -99 && a < 99 || a > 999) // Ограничение значений
    {
        cout << "Ошибка: число должно быть трёхзначным." << endl;
        return 1; 
    }

    if (a % 2 == 0) // Проверка деления на 2 без остатка
    {
        cout << "Чётное" << endl;
    } 
    
    else
    
    {
        cout << "Не чётное" << endl;
    }

    return 0;
}
