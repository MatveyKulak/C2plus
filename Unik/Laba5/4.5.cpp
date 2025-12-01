#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y, R=3;
    cout << "Введите  x: ";
    cin >> x;

    if (x < -4) {
        cout << "y= ";
        cout << -3 << endl;
    }

    else {

         if (x >= -4 && x <= -3) {
            cout << "y= ";  
            cout << 2 * x + 6 << endl;
    }

        else  {

        if (x > -3 && x <= 3) {
            cout << "y= ";
            cout << sqrt(pow(R, 2) - pow(x, 2)) << endl;
            
    }

    else {
        if (x > 3 && x <= 8) {
        cout << "y= "; 
        cout <<  0.6 * x - 1.8 << endl;
        }

        else {
            cout << "y= "; 
            cout << 3 << endl;
        }

    } 
    
    }

    }

    return 0;
}
