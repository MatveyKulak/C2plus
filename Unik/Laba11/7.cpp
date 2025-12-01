/*. Обработка двухмерного массивов в свободной памяти. Реализовать
задачу 5 используя динамический массив.*/

#include <iostream>
using namespace std;

void calculateResultMatrix(int* A, int* B, int size) {
    int sum = *(A + 1 * size + 1) + *(A + 1 * size + 2) + *(A + 2 * size + 1) + *(A + 2 * size + 2);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 1) || (i == 2 && j == 2)) {
                *(B + i * size + j) = *(A + i * size + j);
            } else {
                *(B + i * size + j) = sum;
            }
        }
    }
}

void displayMatrix(int* matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << *(matrix + i*size + j) << " ";
        }
        cout << endl;
    }
}

void enterMatrixElements(int* matrix, int size) {
    cout << "Введите " << size*size << " элементов матрицы:" << endl;
    for (int i = 0; i < size*size; i++) {
        cin >> *(matrix + i);
    }
}

int main() {
    int matrixSize;
    cout << "Введите размер квадратной матрицы: ";
    cin >> matrixSize;

    int* matrixA = new int[matrixSize*matrixSize];
    int* matrixB = new int[matrixSize*matrixSize]();

    enterMatrixElements(matrixA, matrixSize);
    
    cout << "Исходная матрица A:" << endl;
    displayMatrix(matrixA, matrixSize);

    calculateResultMatrix(matrixA, matrixB, matrixSize);

    cout << "Результирующая матрица B:" << endl;
    displayMatrix(matrixB, matrixSize);

    return 0;
}