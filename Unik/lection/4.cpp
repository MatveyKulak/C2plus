#include <iostream>
using namespace std;
const int dlina_str = 510;
// определение функции для подсчета десятичных цифр в строке
int kl_cifr(char g[dlina_str])
{
    int kl = 0;
    for (int j = 0; g[j] != '\0'; ++j)
        if (g[j] >= '0' && g[j] <= '9')
            kl++;
    return kl;
}
int kl_bukv(char *); // прототип функции подсчета количества
                     // латинских букв в строке символов
int main()
{
    setlocale(LC_ALL, "Russian");
    char sm[dlina_str]; // определение массива символов
    // ввод символьной строки
    cout << "Введите строку символов : ";
    cin >> sm;
    // ввод результатов обработки символьной строки
    cout << "Количество цифр в строке = "
         << kl_cifr(sm) << endl;
    cout << "Количество латинских букв в строке = "
         << kl_bukv(sm) << endl;
    // ввод номера символа в строке
    int index;
    cout << "\n Введите номер символа в строке : ";
    cin >> index;
    // вывод соответствующего символа исходной строки
    cout << "\n Символ[" << index << "]=" << sm[index] << endl;
    // вывод строки на экран
    cout
        << '\n'
        << sm << endl;
    return 0;
}
// определение функции для подсчета латинских букв в строке
int kl_bukv(char *z)
{
    int kl = 0;
    for (int j = 0; z[j] != '\0'; ++j)
        if ((z[j] >= 'A' && z[j] <= 'Z') || (z[j] >= 'a' && z[j] <= 'z'))
            kl++;
    return kl;
}