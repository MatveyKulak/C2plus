#include <iostream>

using namespace std;

int main() {
    // Логические переменные
    bool a = true;
    bool b = false;
    
    // Вывод логических выражений и их результатов
    cout << "Логические выражения:" << endl;
    cout << "(1) a && b: " << (a && b) << endl;   // Логическое И
    cout << "(2) a ||  b: " << (a || b) << endl;   // Логическое ИЛИ
    cout << "(3) !a: " << (!a) << endl;           // Логическое НЕ
    cout << "(4) a && !b: " << (a && !b) << endl; // Логическое И с отрицанием
    cout << "(5) !(a ||  b): " << (!(a || b)) << endl; // Отрицание ИЛИ

    return 0;
}