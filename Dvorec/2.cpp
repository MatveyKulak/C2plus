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

    if (a + b > c && a + c > b && b + c > a)
    {
        cout << "Треугольник существует" << endl;
    } 
    
    else 
    
    {
        cout << "Треугольник не существует" << endl;
    }

    return 0;
}