#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
void create_array(int n, double min, double max,
                  double *massiv)
{
    srand((unsigned)time(NULL));
    for (int j = 0; j < n; j++)
        massiv[j] = rand() / (1.0 * RAND_MAX) * (max - min) + min;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    const int razmer = 20;
    double massiv[razmer];
    int n;
    double minzn, maxzn, *m;
    // Ввод количества элементов (n) в одномерном массиве
    do
    {
        cout << "Введите количество элементов массива (n<="
             << razmer << ") : ";
        cin >> n;
    } while (n <= 0 || n > razmer);
    // Определение границ диапазона допустимых значений
    cout << "Введите минимальное значение диапазона: ";
    cin >> minzn;
    cout << "Введите максимальное значение диапазона: ";
    cin >> maxzn;
    if (minzn > maxzn)
    {
        double prom;
        prom = maxzn;
        maxzn = minzn;
        minzn = prom;
    }
    // Запись в указатель m значения адреса вершины массива
    m = &massiv[0];
    // Вызов функции формирования массива
    create_array(n, minzn, maxzn, m);
    // Вывод результатов
    cout << endl
         << "Сформирован массив: ";
    for (int j = 0; j < n; j++)
        cout << massiv[j] << " ; ";
    cout << endl;
    cout << "Размер всего массива = " << sizeof(massiv) << endl
         << ",а размер одного элемента массива = "
         << sizeof(massiv[0]) << endl;
    return 0;
}