//100-1000 на 13 и 17

#include <iostream>

using namespace std;

int main() {

    for (int i = 100; i <= 1000; i ++)
    {
        if (i % 13 == 0 || i % 17 == 0)

        {
            cout << i << endl;
        }
    } 

    return 0;
}