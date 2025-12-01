#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double n , n1, n2, n3, n4; 

     // Ввод n от пользователя
    cout << "Введите значение n: ";
    cin >> n;

    // Вычисление n
    n1 = n;
    cout << "Значение n1: " << n1 << endl;

    n2 = pow(n, 2);
    cout << "Значение n2: " << n2 << endl;
    
    n3 = pow(n, 2) * n;
    cout << "Значение n3: " << n3 << endl;

    n4 = n * n * n * n;
    cout << "Значение n4: " << n4 << endl;
     // Вывод результатов

    return 0;
}