#include <iostream>

using namespace std;

int main() {
    int i=10;

    do {
        if (i % 5 == 0) {
            cout << i << endl;    
        }
        i += 1;
    }
    while (i < 100);
        

    return 0;
}
