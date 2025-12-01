#include <iostream>
#include <string>
using namespace std;

struct Price {
    int rubles;
    int kopecks;
};

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Date {
    int day;
    int month;
    int year;
};

struct Address {
    int postalCode;
    string city;
    string street;
    int house;
    int apartment;
};

struct Student {
    string lastName;
    int recordBookNumber;
    int examGrade;
};

struct ExamRecord {
    string subject;
    int groupNumber;
    Date examDate;
    Student students[25];
};

int main() {
    Student students[25] = {
        {"Иванов", 1001, 7},
        {"Петров", 1002, 4},
        {"Сидоров", 1003, 9},
        {"Кузнецов", 1004, 10},
        {"Смирнов", 1005, 4},
        {"Васильев", 1006, 5},
        {"Павлов", 1007, 6},
        {"Семенов", 1008, 1},
        {"Голубев", 1009, 2},
        {"Виноградов", 1010, 8},
        {"Богданов", 1011, 9},
        {"Воробьев", 1012, 10},
        {"Федоров", 1013, 4},
        {"Михайлов", 1014, 5},
        {"Белов", 1015, 3},
        {"Ковалев", 1016, 1},
        {"Сергеев", 1017, 1},
        {"Николаев", 1018, 6},
        {"Тихонов", 1019, 6},
        {"Соловьев", 1020, 8},
        {"Дмитриев", 1021, 7},
        {"Васильева", 1022, 4},
        {"Петрова", 1023, 4},
        {"Сидорова", 1024, 3},
        {"Кузнецова", 1025, 5}
    };

    Price p1 = {100, 50};
    Price* pPtr = &p1;
    
    cout << "Цена: " << p1.rubles << " руб. " << p1.kopecks << " коп." << endl;
    cout << "Цена через указатель: " << pPtr->rubles << " руб. " << pPtr->kopecks << " коп." << endl;

    Time t1 = {14, 30, 45};
    Time* tPtr = &t1;
    
    cout << "Время: " << t1.hours << ":" << t1.minutes << ":" << t1.seconds << endl;
    cout << "Время через указатель: " << tPtr->hours << ":" << tPtr->minutes << ":" << tPtr->seconds << endl;

    Date d1 = {15, 5, 2023};
    Date* dPtr = &d1;
    
    cout << "Дата: " << d1.day << "." << d1.month << "." << d1.year << endl;
    cout << "Дата через указатель: " << dPtr->day << "." << dPtr->month << "." << dPtr->year << endl;

    Address a1 = {123456, "Москва", "Ленина", 10, 25};
    Address* aPtr = &a1;
    
    cout << "Адрес: " << a1.postalCode << ", " << a1.city << ", " 
         << a1.street << " ул., д. " << a1.house << ", кв. " << a1.apartment << endl;
    cout << "Адрес через указатель: " << aPtr->postalCode << ", " << aPtr->city << ", " 
         << aPtr->street << " ул., д. " << aPtr->house << ", кв. " << aPtr->apartment << endl;

    ExamRecord er1;
    er1.subject = "Программирование";
    er1.groupNumber = 101;
    er1.examDate = {15, 5, 2023};
    
    for (int i = 0; i < 25; i++) {
        er1.students[i] = students[i];
    }

    cout << "Экзаменационная ведомость: " << er1.subject << ", группа " << er1.groupNumber 
         << ", дата: " << er1.examDate.day << "." << er1.examDate.month << "." << er1.examDate.year << endl;
    
    cout << "Список студентов:" << endl;
    for (int i = 0; i < 25; i++) {
        cout << i+1 << ". " << er1.students[i].lastName 
             << ", зачетка №" << er1.students[i].recordBookNumber 
             << ", оценка: " << er1.students[i].examGrade << endl;
    }

    return 0;
}