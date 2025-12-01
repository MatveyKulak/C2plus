#include <iostream>

using namespace std;

int main() {
    int i=10;

    for (i; i < 100; i += 1)
     if (i % 5 == 0) { 
            cout << i << endl; 
        }

    return 0;
}

