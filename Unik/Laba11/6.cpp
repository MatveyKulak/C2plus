/*Обработка одномерного массивов в свободной памяти. Реализовать
задачу 2 используя динамический массив. В тексте программы запрещается
применять операцию индексации (a[i], a[i+1] и .т.п.), т.е. массив необходимо
обрабатывать только с использованием указателей.*/

#include <iostream>
using namespace std;

void inputArray(int* arr, int size) {
    cout << "Введите " << size << " элементов массива:" << endl;
    int* end = arr + size;
    while (arr < end) {
        cin >> *arr++;
    }
}

void printArray(int* arr, int size) {
    cout << "Элементы массива: ";
    int* end = arr + size;
    while (arr < end) {
        cout << *arr++ << " ";
    }
    cout << endl;
}

void sumBetweenMaxMin(int* arr, int size) {
    int* max = arr;
    int* min = arr;
    int* end = arr + size;

    for (int* p = arr; p < end; p++) {
        if (*p > *max) {
            max = p;
        }
        if (*p <= *min) {
            min = p;
        }
    }

    if (max > min) {
        cout << "Максимальный элемент встречается позже минимального." << endl;
        return;
    }

    int sum = 0;
    for (int* p = max + 1; p < min; p++) {
        sum += *p;
    }
    cout << "Сумма элементов между первым максимальным и последним минимальным: " << sum << endl;
}

void randomArray(int* arr, int size, int min, int max) {
    for (int* p = arr; p < arr + size; p++) {
        *p = min + rand() % (max - min + 1);
    }
}

int main() {

    cout << "Выберите способ ввода данных:" << endl;
    cout << "1. Вводить размер и элементы массива вручную." << endl;
    cout << "2. Использовать генератор случайных значений." << endl;

    int choice;
    cin >> choice;

    int size = 10 + rand() % (23 - 10 + 1);
    int* arr = new int[size];

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
