#include <iostream>
using namespace std;

int main() {
  system("chcp 1251 > nul");
  char letter;

  cout << "Введите букву русского алфавита от а до и: ";
  cin >> letter;
  switch (letter) {
  case 'а': cout << "Арбуз" << endl; break;
  case 'б': cout << "Бегемот" << endl; break;
  case 'в': cout << "Ваза" << endl; break;
  case 'г': cout << "Груша" << endl; break;
  case 'д': cout << "Дом" << endl; break;
  case 'е': cout << "Егор" << endl; break;
  case 'ё': cout << "Ёж" << endl; break;
  case 'ж': cout << "Жираф" << endl; break;
  case 'з': cout << "Зебра" << endl; break;
  case 'и': cout << "Игра" << endl; break;
  default: cout << "Введена неверная буква." << endl; break;
  }

  return 0;
}




    