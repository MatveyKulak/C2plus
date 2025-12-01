/*1.9. Подсчитать сумму элементов, расположенных между первым
максимальным и последним минимальными элементами. Если максимальный
элемент встречается позже минимального, то выдать сообщение об этом.*/

#include <iostream>
using namespace std;

void inputArray(int arr[], int size) {
    cout << "Введите " << size << " элементов массива:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(int arr[], int size) {
    cout << "Элементы массива: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sumBetweenMaxMin(int arr[], int size) {
    int max = arr[0];
    int min = arr[0];
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
        if (arr[i] <= min) {
            min = arr[i];
            minIndex = i;
        }
    }

    if (maxIndex > minIndex) {
        cout << "Максимальный элемент встречается позже минимального." << endl;
    } else {
        int sum = 0;
        for (int i = maxIndex + 1; i < minIndex; i++) {
            sum += arr[i];
        }
        cout << "Сумма элементов между первым максимальным и последним минимальным: " << sum << endl;
    }
}

void randomArray(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

int main() {
    int size = 10;
    int arr[size];

    inputArray(arr, size);
    printArray(arr, size);
    sumBetweenMaxMin(arr, size);

    randomArray(arr, size, 1, 100);
    cout << "Случайно сгенерированный массив:" << endl;
    printArray(arr, size);
    sumBetweenMaxMin(arr, size);

    return 0;
}
