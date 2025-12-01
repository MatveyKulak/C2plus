#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите n (0-31): ";
    cin >> n;
    
    if (n < 0 || n >= 32) {
        cout << "Ошибка: n должно быть в диапазоне 0-31" << endl;
        return 1;
    }
    
    cout << "Результат: " << (n << 1) << endl;
    
    return 0;
}