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

    if (a == -b || a == -c) // Проверка на противоположную пару
    {
        cout << "Число a имеет взаимно противополжную пару" << endl;
    }

    else

    { 
        if (b == -a || b == -c)
        {
            cout << "Число b имеет взаимно противополжную пару" << endl;
        }

        else
        {
            
        cout << "Отсутсвуют взаимно протвоположные пары" << endl;
        
        }
    }

    return 0;
}