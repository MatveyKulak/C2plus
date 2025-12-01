#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x;
    cout << "Введите  x: ";
    cin >> x;

    if (x <= -15) {
        cout << pow(x, 3) / 15 << endl;
    }

    else {

         if (x < 6 && x > -6) {
        cout << abs(x) << endl;
    }

        else  {
        cout << sqrt(x + 4) << endl;
    }
    
    }

   

    return 0;
}