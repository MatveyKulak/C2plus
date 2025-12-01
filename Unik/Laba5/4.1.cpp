#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y, R=2;
    cout << "Введите  x: ";
    cin >> x;

    if (x <= 0) {
        cout << "y= ";
        cout << -0.5 * x << endl;
    }

    else {

         if (x > 0 && x <= 2) {
            cout << "y= ";
            cout << -sqrt(pow(R, 2) - pow(x, 2)) + 2 << endl;
    }

        else  {

        if (x > 2 && x <= 4) {
            cout << "y= ";
            cout << sqrt(pow(R, 2) - pow(x - 2, 2)) << endl;
            
    }

    else {
        cout << "y= ";
        cout << -x + 4 << endl;
    }
    
    }

    }

    return 0;
}