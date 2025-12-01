#include <iostream>
using namespace std;

int main() {
    int month,day,days;

    cout << "Введите номер месяца: ";
    cin >> month;

        if (month < 1 || month > 12) {
        cout << "Ошибка!" << endl;
        return 1;
        }

    cout << "Введите номер дня: ";
    cin >> day;

        if (day < 1 || day > 31) {
        cout << "Ошибка!" << endl;
        return 1;
        }

    if (month == 1) {
    days = 31 - day;
    }
    else if (month == 2)
    days = 28 - day;
    else if (month == 3)
    days = 31 - day;
    else if (month == 4)
    days = 30 - day;
    else if (month == 5)
    days = 31 - day;
    else if (month == 6)
    days = 30 - day;
    else if (month == 7)
    days = 31 - day;
    else if (month == 8)
    days = 31 - day;
    else if (month == 9)
    days = 30 - day;
    else if (month == 10)
    days = 31 - day;
    else if (month == 11)
    days = 30 - day;
    else if (month == 12)
    days = 31 - day;

switch (days) {
case 1:  cout << "Осталось до конца месяца 1 день"  << endl;  break;
case 2:  cout << "Осталось до конца месяца 2 дня" << endl;  break;
case 3:  cout << "Осталось до конца месяца 3 дня" << endl;  break;
case 4:  cout << "Осталось до конца месяца 4 дня" << endl;  break;
case 5:  cout << "Осталось до конца месяца 5 дней" << endl;  break;
case 6:  cout << "Осталось до конца месяца 6 дней" << endl;  break;
case 7:  cout << "Осталось до конца месяца 7 дней" << endl;  break;
case 8:  cout << "Осталось до конца месяца 8 дней" << endl;  break;
case 9:  cout << "Осталось до конца месяца 9 дней" << endl;  break;
case 10:  cout << "Осталось до конца месяца 10 дней" << endl;  break;
case 11:  cout << "Осталось до конца месяца 11 дней" << endl;  break;
case 12:  cout << "Осталось до конца месяца 12 дней" << endl;  break;
case 13:  cout << "Осталось до конца месяца 13 дней" << endl;  break;
case 14:  cout << "Осталось до конца месяца 14 дней" << endl;  break;
case 15:  cout << "Осталось до конца месяца 15 дней" << endl;  break;
case 16:  cout << "Осталось до конца месяца 16 дней" << endl;  break;
case 17:  cout << "Осталось до конца месяца 17 дней" << endl;  break;
case 18:  cout << "Осталось до конца месяца 18 дней" << endl;  break;
case 19:  cout << "Осталось до конца месяца 19 дней" << endl;  break;
case 20:  cout << "Осталось до конца месяца 20 дней" << endl;  break;
case 21:  cout << "Осталось до конца месяца 21 дней" << endl;  break;
case 22:  cout << "Осталось до конца месяца 22 дней" << endl;  break;
case 23:  cout << "Осталось до конца месяца 23 дней" << endl;  break;
case 24:  cout << "Осталось до конца месяца 24 дней" << endl;  break;
case 25:  cout << "Осталось до конца месяца 25 дней" << endl;  break;
case 26:  cout << "Осталось до конца месяца 26 дней" << endl;  break;
case 27:  cout << "Осталось до конца месяца 27 дней" << endl;  break;
case 28:  cout << "Осталось до конца месяца 28 дней" << endl;  break;
case 29:  cout << "Осталось до конца месяца 29 дней" << endl;  break;
case 30:  cout << "Осталось до конца месяца 30 дней" << endl;  break;
default: cout << "Ошибка!";

}

    return 0;
}

