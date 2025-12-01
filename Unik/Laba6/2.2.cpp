/*С 1 января 1990 года по некоторый день прошло n дней, определить
название текущего месяца.*/

#include <iostream>

using namespace std;

int main() {
int days, year=1990, month=0;

cout << "Введите кол-во прошедших дней: "; 
cin >> days;

int Jan = 31, Feb = 28, Mar = 31, Apr = 30, May = 31, Jun = 30, Jul = 31, Aug= 31, Sep = 30, Oct = 31, Nov = 30, Dec = 31;

if (days <= Jan) {
    month = 1;
}
if (days <= Jan + Feb) {
    month = 2;
}
if (days <= Jan + Feb + Mar) {
    month = 3;
}
if (days <=  Jan + Feb + Mar + Apr) {
    month = 4;
}
if (days <= Jan + Feb + Mar + Apr + May) {
    month = 5;
}
if (days <= Jan + Feb + Mar + Apr + May + Jun) {
    month = 6;
}
if (days <= Jan + Feb + Mar + Apr + May + Jun + Jul) {
    month = 7;
}
if (days <= Jan + Feb + Mar + Apr + May + Jun + Jul + Aug) {
    month = 8;
}
if (days <= Jan + Feb + Mar + Apr + May + Jun + Jul + Aug + Sep) {
    month = 9;
}
if (days <= Jan + Feb + Mar + Apr + May + Jun + Jul + Aug + Sep + Oct) {
    month = 10;
}
if (days <= Jan + Feb + Mar + Apr + May + Jun + Jul + Aug + Sep + Oct + Nov) {
    month = 11;
}
if (days <= Jan + Feb + Mar + Apr + May + Jun + Jul + Aug + Sep + Oct + Nov + Dec) {
    month = 12;
}

switch (month) {
case 1:  cout << "Январь" << endl;  break;
case 2:  cout << "Февраль" << endl;  break;
case 3:  cout << "Март" << endl;  break;
case 4:  cout << "Апрель" << endl;  break;
case 5:  cout << "Май" << endl;  break;
case 6:  cout << "Июнь" << endl;  break;
case 7:  cout << "Июль" << endl;  break;
case 8:  cout << "Август" << endl;  break;
case 9:  cout << "Сентябрь" << endl;  break;
case 10:  cout << "Октябрь" << endl;  break;
case 11:  cout << "Ноябрь" << endl;  break;
case 12:  cout << "Декабрь" << endl;  break;
default: cout << "Ошибка!";

}

 return 0;
}
