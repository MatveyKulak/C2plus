#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x;
    
    cout << "Введите  x: ";
    cin >> x;

    if (x <= -15) {
        cout << pow(x, -2) << endl;
    }

    else {

         if (x < 15 && x > -15) {
        cout << 10 << endl;
    }

        else  {
        cout << -x << endl;
    }
    
    }

    return 0;
}