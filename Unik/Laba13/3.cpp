#include <iostream>
#include <string>
using namespace std;

struct Student {
    string fullName;
    int age;
    int course;
    int grades[3];
};

void inputStudent(Student &s) {
    cout << "Введите ФИО: ";
    cin.ignore();
    getline(cin, s.fullName);
    cout << "Введите возраст: ";
    cin >> s.age;
    cout << "Введите курс: ";
    cin >> s.course;
    cout << "Введите оценки по 3 предметам: ";
    for (int i = 0; i < 3; ++i) {
        cin >> s.grades[i];
    }
}

void printStudent(const Student &s) {
    cout << "ФИО: " << s.fullName << ", Возраст: " << s.age 
         << ", Курс: " << s.course << ", Оценки: ";
    for (int i = 0; i < 3; ++i) {
        cout << s.grades[i] << (i < 2 ? ", " : "");
    }
    cout << endl;
}

int countExcellentStudents(const Student students[], int n, int subjectIndex, int course) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (students[i].course == course && students[i].grades[subjectIndex] >= 9) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Введите количество студентов: ";
    cin >> n;

    Student* students = new Student[n];

    for (int i = 0; i < n; ++i) {
        cout << "Студент " << i + 1 << ":" << endl;
        inputStudent(students[i]);
    }

    cout << "Информация о студентах:" << endl;
    for (int i = 0; i < n; ++i) {
        printStudent(students[i]);
    }

    int course, subjectIndex;
    cout << "Введите курс для проверки: ";
    cin >> course;
    cout << "Введите номер предмета (1, 2, 3): ";
    cin >> subjectIndex;

    int excellentCount = countExcellentStudents(students, n, subjectIndex - 1, course);
    cout << "Количество отличников по предмету " << subjectIndex
         << " на курсе " << course << ": " << excellentCount << endl;

    return 0;
}