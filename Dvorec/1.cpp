#include <iostream>

using namespace std;

int main() {
    double a, b, c;

    cout << "Введите  a: ";
    cin >> a;
    cout << "Введите  b: ";
    cin >> b;
    cout << "Введите  c: ";
    cin >> c;

    if (a > b && a > c)
    {
        cout << "Число a больше" << endl;
    }

    else

    { 
        if (b > a && b > c)
        {
            cout << "Число b больше" << endl;
        }

        else
        {
            if (c > a && c > b)
            cout << "Число c больше" << endl;

            else
            {
                cout << "Числа a, b и c равны" << endl;
            }
        }
    }

    return 0;
}