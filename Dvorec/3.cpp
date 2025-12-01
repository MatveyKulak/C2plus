#include <iostream>

using namespace std;

int main() {
    double a, b, c;

    cout << "Введите сторону a: ";
    cin >> a;
    cout << "Введите сторону b: ";
    cin >> b;
    cout << "Введите сторону c: ";
    cin >> c;

    if (a == c && a == b ) 
    {
        cout << "Треугольник равностронний" << endl;
    } 
    
    else 
    
    {
        cout << "Треугольник не равносторонний" << endl;
    }

    return 0;
}