/*Пользователь вводит число с клавиатуры. Составьте программу, которая, в
случае, если данное число положительное прибавляет к нему 3, а если
отрицательное – вычитает 3.
*/
#include <iostream>

using namespace std;

int main() {
    double a;

    cout << "Введите  a: ";
    cin >> a;

    if (a > 0)
    {
        a += 3;
        cout << a << endl;
    }

    else
    { 
        a -= 3;
        cout << a << endl;
    }

    return 0;
}