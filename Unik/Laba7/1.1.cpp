/*Вывод всех двухзначных чисел, кратных 5.*/
#include <iostream>

using namespace std;

int main() {
    int i=10;

    while (i < 100)
    {
        if (i % 5 == 0) {
            cout << i << endl;    
        }
        i += 1;
    }

    return 0;
}

