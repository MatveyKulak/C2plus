/*2.1 Дан номер месяца и порядковый номер дня месяца, вывести на экран
количество дней оставшихся до конца месяца. Не забываем про февраль!*/
#include <iostream>
using namespace std;

int days(int month) {
    switch (month) {
    case 1: return 31;
    case 2: return 28; 
    case 3: return 31;
    case 4: return 30; 
    case 5: return 31; 
    case 6: return 30; 
    case 7: return 31; 
    case 8: return 31; 
    case 9: return 30; 
    case 10: return 31; 
    case 11: return 30; 
    case 12: return 31; 
    default: return 0; 
    }
}

int main() {
    int day, month;

    cout << "Введите номер месяца: ";
    cin >> month;
    cout << "Введите номер дня: ";
    cin >> day;

    if (month < 1 || month > 12) {
        cout << "Ошибка!" << endl;
        return 1;
    }

    if (day < 1  || day > days(month)) {
        cout << "Ошибка!" << endl;
        return 1;
    }

    int remain = days(month) - day;

    cout << "До конца месяца осталось " << remain << " дней." << endl;

    return 0;
}


   