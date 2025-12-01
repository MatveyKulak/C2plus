#include <iostream>
using namespace std;
#include <stdlib.h>    // для подключения srand(), rand()и RAND_MAX;
#include <time.h>      // для подключения функции time();
const int razmer = 12; // определяется целочисленная константа
int main()
{
    int mas[razmer];
    srand((unsigned)time(NULL)); // Seed (семя) Random -
    // инициализатор генератора
    for (int i = 0; i < razmer; i++)
    {
        mas[i] = rand() - RAND_MAX / 2;
        cout << mas[i] << endl;
    }
    cout << RAND_MAX << endl;
    return 0;
}