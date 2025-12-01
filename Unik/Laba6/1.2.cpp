/*При изучении чисел детьми им называют число и просят сказать любую
фразу, содержащее это число. Напишите программу, которая принимает число от
1 до 7 и выводит фразу, содержащее это число. (Например, три кота) */

#include <iostream>

using namespace std;

int main() {
int phrase;

cout << "Введите цифру от 1 до 7: "; 
cin >> phrase;

switch (phrase) {
case 1:  cout << "Первая" << endl;  break;
case 2:  cout << "Вторая" << endl;  break;
case 3:  cout << "Третья" << endl;  break;
case 4:  cout << "Четвёртая" << endl;  break;
case 5:  cout << "Пятая" << endl;  break;
case 6:  cout << "Шестая" << endl;  break;
case 7:  cout << "Седьмая" << endl;  break;
default: cout << "Ошибка: введите цифру от 1 до 7";

}

 return 0;
}
