/*2.4. Сгенерировать массив символов в диапазоне [-100;-50] со случайным
количеством (из промежутка [10;23]). .*/

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

    cout << "Выберите способ ввода данных:" << endl;
    cout << "1. Вводить размер и элементы массива вручную." << endl;
    cout << "2. Использовать генератор случайных значений." << endl;

    int choice;
    cin >> choice;

    int size = 10 + rand() % (23 - 10 + 1);
    int arr[size];

    if (choice == 1) {
        inputArray(arr, size);
    } else {
        cout << "Сгенерированный размер массива: " << size << endl;
        randomArray(arr, size, -100, -50);
    }

    printArray(arr, size);
    sumBetweenMaxMin(arr, size);

    return 0;
}
