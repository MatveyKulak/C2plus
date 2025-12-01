#include <iostream>
using namespace std;

int main() {
    int A, i;
    cout << "Введите число A и номер бита i (0-31): ";
    cin >> A >> i;
    
    if (i < 0 || i >= 32) {
        cout << "Ошибка: i должно быть в диапазоне 0-31" << endl;
        return 1;
    }
    
    cout << "Результат: " << (A ^ (1 << i)) << endl;
    
    return 0;
}