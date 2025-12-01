#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x;
    cout << "Введите  x: ";
    cin >> x;

    if (x <= -5) {
        cout << pow(x, 2) << endl;
    }

    else {

         if (x < 3 && x > -5) {
        cout << sin(abs(x)) << endl;
    }

        else  {
        cout << 2 * x << endl;
    }
    
    }

   

    return 0;
}