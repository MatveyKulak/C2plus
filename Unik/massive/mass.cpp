#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    const int size = 10;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 20;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}