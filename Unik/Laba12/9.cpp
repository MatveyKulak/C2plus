#include <iostream>
using namespace std;

int main() {
    int A;
    cout << "Введите число A (0-255): ";
    cin >> A;
    
    if (A < 0 || A > 255) {
        cout << "Ошибка: A должно быть в диапазоне 0-255" << endl;
        return 1;
    }
    
    cout << "Результат: ";
    for (int i = 7; i >= 0; i--) {
        cout << ((A >> i) & 1);
    }
    cout << endl;
    
    return 0;
}