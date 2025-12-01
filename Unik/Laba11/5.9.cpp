/*Дана действительная матрица [aij]i,j=1,…,n. Получить
действительную матрицу [bij]i,j=1,…,n, элемент bij
которой равен сумме элементов данной матрицы,
расположенных в заштрихованной области,
определяемой индексами i, j как показано на рисунке. */

#include <iostream>
using namespace std;

const int maxSize = 6;

void matrixB(int A[maxSize][maxSize], int B[maxSize][maxSize], int n) {
    int sum = A[0][1] + A[0][2] + A[1][1] + A[1][2];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 && j >= 1) || (i == 1 && j >= 1)) {
                B[i][j] = A[i][j];  
            } else {
                B[i][j] = sum;  
            }
        }
    }
}

void printMatrix(int matrix[maxSize][maxSize], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void inputMatrix(int matrix[maxSize][maxSize], int n) {
    cout << "Введите " << n*n << " элементов матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

int main() {
    int n;
    cout << "Введите размер матрицы (макс. " << maxSize << "): ";
    cin >> n;

    if (n > maxSize) {
        cout << "Размер матрицы превышает допустимый предел." << endl;
        return 1;
    }

    int A[maxSize][maxSize];
    int B[maxSize][maxSize];

    inputMatrix(A, n);

    cout << "Матрица A:" << endl;
    printMatrix(A, n);

    matrixB(A, B, n);

    cout << "Матрица B:" << endl;
    printMatrix(B, n);

    return 0;
}