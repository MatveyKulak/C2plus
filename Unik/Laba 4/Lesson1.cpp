#include <iostream>

using namespace std;

int main() {
    char a, b;

    cout << "Введите первую букву имени: ";
    cin >> a;

    cout << "Введите первую букву фамилии: ";
    cin >> b;

    cout << "Первая буква фамилии: " << a << " (ASCII код: " << static_cast<int>(a) << ")" << endl; // Перевод в ASCII код
    cout << "Первая буква имени: " << b << " (ASCII код: " << static_cast<int>(b) << ")" << endl;

    return 0;
    }