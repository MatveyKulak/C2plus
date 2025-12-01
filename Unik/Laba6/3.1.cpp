/*3.1 Дан номер масти m (1-4) и номер достоинства карты k (6-14). Достоинства
определяются по следующему правилу: "туз" - 14, "король" - 13, "дама" - 12, "валет"
- 11, "десятка" - 10, …, "шестерка" - 6. Определить полное название
соответствующей карты в виде "дама пик", "шестерка бубен" и т.д.*/
#include <iostream>
using namespace std;

int main() {
    int m,k;

    cout << "Введите номер масти(1 - пики, 2 - червы, 3 - бубны, 4 - трефы): ";
    cin >> m;
    cout << "Введите номер карты от 6 до 14: ";
    cin >> k;

switch (k) {
    case 6:cout << "Шестёрка "; break;
    case 7:cout << "Семёрка ";break;
    case 8:cout << "Восьмёрка ";break;
    case 9:cout << "Девятка ";break;
    case 10:cout << "Десятка ";break;
    case 11:cout << "Валет ";break;
    case 12:cout << "Дама ";break;
    case 13:cout << "Король ";break;
    case 14:cout << "Туз ";break;
    default:cout << "Ошибка! ";break;
    }

switch (m) {
    case 1:cout << "Пик" << endl; break;
    case 2:cout << "Червей" << endl;break;
    case 3:cout << "Бубен" << endl;break;
    case 4:cout << "Треф" << endl;break;
    default:cout << "Ошибка!" << endl;break;
    }
    return 0;
}



