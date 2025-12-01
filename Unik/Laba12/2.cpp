#include <iostream>
using namespace std;

int add(int a, int b) {
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int main() {
    int n, m;
    cout << "Введите два разных числа n и m (0-31): ";
    cin >> n >> m;
    
    if (n < 0 || n >= 32 || m < 0 || m >= 32) {
        cout << "Ошибка: числа должны быть в диапазоне 0-31" << endl;
        return 1;
    }
    
    if (n == m) {
        cout << "Ошибка: числа должны быть разными" << endl;
        return 1;
    }
    
    cout << "Результат: " << add(n << 1, m << 1) << endl;
    
    return 0;
}