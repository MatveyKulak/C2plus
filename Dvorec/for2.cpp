#include <iostream>

using namespace std;

int main() {
    int multiplication = 1 ;

    for (int i = 1; i <= 10; i ++)
    {
        multiplication *= i; 
    } 

    cout << multiplication << endl;

    return 0;
}
