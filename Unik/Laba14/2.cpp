#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student {
    char fullName[100];
    int age;
    char gender;
    int course;
    float grades[3];
};

void createFile(const char* filename);
void viewFile(const char* filename);
void addRecord(const char* filename);
void deleteRecord(const char* filename);
void updateRecord(const char* filename);
void findFailingStudents(const char* filename, int course);

int main() {
    const char* filename = "students.dat";
    int choice, course;

    do {
        cout << "Меню:" << endl;
        cout << "1. Создать файл" << endl;
        cout << "2. Просмотр содержимого файла" << endl;
        cout << "3. Добавить запись" << endl;
        cout << "4. Удалить запись" << endl;
        cout << "5. Корректировка записи" << endl;
        cout << "6. Найти неуспевающих студентов" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createFile(filename);
                break;
            case 2:
                viewFile(filename);
                break;
            case 3:
                addRecord(filename);
                break;
            case 4:
                deleteRecord(filename);
                break;
            case 5:
                updateRecord(filename);
                break;
            case 6:
                cout << "Введите курс: ";
                cin >> course;
                findFailingStudents(filename, course);
                break;
            case 0:
                cout << "Выход." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);

    return 0;
}

void createFile(const char* filename) {
    ofstream outFile(filename, ios::binary);
    outFile.close();
}

void viewFile(const char* filename) {
    ifstream inFile(filename, ios::binary);

    Student student;
    cout << "ФИО\tВозраст\tПол\tКурс\tУспеваемость\n";
    cout << "---------------------------------------------\n";
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        cout << student.fullName << "\t" << student.age << "\t" << student.gender
             << "\t" << student.course << "\t";
        for (float grade : student.grades) {
            cout << grade << " ";
        }
        cout << endl;
    }
    inFile.close();
}

void addRecord(const char* filename) {
    ofstream outFile(filename, ios::binary | ios::app);

    Student student;
    cout << "Введите ФИО: ";
    cin.ignore();
    cin.getline(student.fullName, 100);
    cout << "Введите возраст: ";
    cin >> student.age;
    cout << "Введите пол (M/F): ";
    cin >> student.gender;
    cout << "Введите курс: ";
    cin >> student.course;
    cout << "Введите оценки по 3 предметам: ";
    for (int i = 0; i < 3; ++i) {
        cin >> student.grades[i];
    }

    outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
    outFile.close();
    cout << "Запись добавлена." << endl;
}

void deleteRecord(const char* filename) {
    ifstream inFile(filename, ios::binary);

    Student students[100];
    int count = 0;
    Student student;

    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        students[count++] = student;
    }
    inFile.close();

    cout << "Введите ФИО студента для удаления: ";
    cin.ignore();
    char name[100];
    cin.getline(name, 100);

    ofstream outFile(filename, ios::binary);
    for (int i = 0; i < count; ++i) {
        if (strcmp(students[i].fullName, name) != 0) {
            outFile.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
        }
    }
    outFile.close();
    cout << "Запись удалена." << endl;
}

void updateRecord(const char* filename) {
    fstream file(filename, ios::binary | ios::in | ios::out);

    cout << "Введите ФИО студента для корректировки: ";
    cin.ignore();
    char name[100];
    cin.getline(name, 100);

    Student student;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (strcmp(student.fullName, name) == 0) {
            found = true;
            cout << "Введите новый возраст: ";
            cin >> student.age;
            cout << "Введите новый пол (M/F): ";
            cin >> student.gender;
            cout << "Введите новый курс: ";
            cin >> student.course;
            cout << "Введите новые оценки по 3 предметам: ";
            for (int i = 0; i < 3; ++i) {
                cin >> student.grades[i];
            }
            file.seekp(-static_cast<int>(sizeof(Student)), ios::cur);
            file.write(reinterpret_cast<char*>(&student), sizeof(Student));
            break;
        }
    }
    
    file.close();
    if (found) {
        cout << "Запись обновлена." << endl;
    } else {
        cout << "Студент не найден." << endl;
    }
}

void findFailingStudents(const char* filename, int course) {
    ifstream inFile(filename, ios::binary);

    ofstream outFile("failing_students.dat", ios::binary);
    Student student;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.course == course) {
            bool failing = false;
            for (float grade : student.grades) {
                if (grade < 3.0) {
                    failing = true;
                    break;
                }
            }
            if (failing) {
                outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
            }
        }
    }

    inFile.close();
    outFile.close();
    cout << "Неуспевающие студенты записаны в failing_students.dat." << endl;
}