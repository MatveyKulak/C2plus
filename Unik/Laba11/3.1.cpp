/*3.1 Отсортировать массив символов по возрастанию их кодов.*/

#include <iostream>
using namespace std;

void inputArray(char arr[], int size) {
    cout << "Введите " << size << " элементов массива (символы):" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(char arr[], int size) {
    cout << "Элементы массива: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortArray(char arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int size = 10;
    char arr[size];

    cout << "Выберите способ ввода данных:" << endl;
    cout << "1. Ввести массив символов вручную." << endl;
    cout << "2. Использовать заранее заданный массив." << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        inputArray(arr, size);
    } else {
        char predefinedArray[size] = {'g', 'b', 'a', 'd', 'e', 'f', 'c', 'i', 'h', 'j'};
        for (int i = 0; i < size; i++) {
            arr[i] = predefinedArray[i];
        }
    }

    printArray(arr, size);
    sortArray(arr, size);
    
    cout << "Отсортированный массив по возрастанию кодов символов:" << endl;
    printArray(arr, size);

    return 0;
}