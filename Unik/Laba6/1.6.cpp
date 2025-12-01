/*Введите год и сообщите соответствующее ему животное согласно
Восточному календарю.*/

#include <iostream>

using namespace std;

int main() {
int year;

cout << "Введите год: "; 
cin >> year;

switch (year % 12) {
case 0:  cout << "Обезьяна" << endl;  break;
case 1:  cout << "Петух" << endl;  break;
case 2:  cout << "Собака" << endl;  break;
case 3:  cout << "Свинья" << endl;  break;
case 4:  cout << "Крыса" << endl;  break;
case 5:  cout << "Бык" << endl;  break;
case 6:  cout << "Тигр" << endl;  break;
case 7:  cout << "Кролик" << endl;  break;
case 8:  cout << "Дракон" << endl;  break;
case 9:  cout << "Змея" << endl;  break;
case 10:  cout << "Лошадь" << endl;  break;
case 11:  cout << "Коза" << endl;  break;
default: cout << "Ошибка: введите год";

}

 return 0;
}