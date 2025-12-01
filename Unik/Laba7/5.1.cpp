/*Реализуйте вложенные циклы для вывода на экран чисел следующим
образом:*/
#include <iostream>
using namespace std;

int main() {
int i, j;

    for (i = 0; i < 4; i++) {
    for (j = 1; j <= 10; j++) {
        cout << j << "  ";
    }
    cout << endl;
    }
    return 0;
}