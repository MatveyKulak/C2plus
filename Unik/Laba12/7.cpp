#include <iostream>
using namespace std;

int main() {
    int A, n;
    cout << "Введите число A и количество бит n (0-32): ";
    cin >> A >> n;
    
    if (n < 0 || n > 32) {
        cout << "Ошибка: n должно быть в диапазоне 0-32" << endl;
        return 1;
    }
    
    cout << "Результат: " << (A & ((1 << n) - 1)) << endl;
    
    return 0;
}