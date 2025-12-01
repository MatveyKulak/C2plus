/* Вычислить и вывести на экран в виде таблицы значения функции,
заданной с помощью ряда Тейлора, на интервале от xнач. до xкон. с шагом dx и с
точностью e (рассмотреть разные ситуации е=0.1,0.01,0.001). Каждая строка
таблицы должна содержать значение аргумента, значение функции и
количество просуммированных членов ряда.*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double first_x,last_x, dx, e, function, term;   
    int n, sum; 

    cout << "Введите начальный х: ";
    cin >> first_x;
    cout << "Введите конечный x: ";
    cin >> last_x;
    cout << "Введите шаг: ";
    cin >> dx;
    cout << "Введите точность е (0.1, 0.01, 0.001): ";
    cin >> e;

    cout << " x" << "     Function(e^x)" << "  Number" << endl;
    cout << "_____________________________" << endl;

    for (first_x; first_x <= last_x; first_x += dx) {
        function = 1.0;  
        term = 1.0;     
        sum = 1;    

        for (n = 1; abs(term) >= e; ++n) {
            term *= first_x / n;     
            function += term;   
            ++sum;      
        }

        cout << fixed << setprecision(1) << first_x 
             << "       " << fixed << setprecision(3) << function 
             << "         " << sum << endl;
    }

    return 0;
}

