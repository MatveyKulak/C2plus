#include <iostream>

using namespace std;

int main() {
    double a, b;

    cout << "Введите  a: ";
    cin >> a;
    cout << "Введите  b: ";
    cin >> b;

    if (a == b)
    {
        return 1;
    }
     
     else 

    { 
        if (a > b)

        {
            cout << a-b << endl;
        }
        
        else

        {
            cout << b-a << endl;
        }
    }

    return 0;
}