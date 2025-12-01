#include <iostream>

using namespace std;

int main() {
    double a, b;

    cout << "Введите  a: ";
    cin >> a;
    cout << "Введите  b: ";
    cin >> b;

    if (a == 0 || b == 0)
    {
        return 1;
    }

    else

    { 

        if (a > 0 && b > 0)
        {
            cout << "Числа a и b имеют одинаковый знак" << endl;
        }

        else
        {
            cout << "Числа a и b имеют не одинаковый знак" << endl;
        }
        
    }

    return 0;
}