#include <iostream>
#include <string>

using namespace std;

class MedWorker {
public:
    string name;
    string position;

    MedWorker(const string& n, const string& p) : name(n), position(p) {}
    virtual ~MedWorker() {}

    virtual void display() const = 0;
    virtual int calculateZp() const = 0;
};

class Nurse : public MedWorker {
private:
    int hours;

public:
    Nurse(const string& n, int h) : MedWorker(n, "Медсестра"), hours(h) {}
    
    int calculateZp() const override {
        return hours * 1;
    }
    
    void display() const override {
        cout << "Имя: " << name << ", Должность: " << position
             << ", Отработано часов: " << hours
             << ", Доход: " << calculateZp() << " р.";
    }
};

class Doctor : public MedWorker {
private:
    int hours;

public:
    Doctor(const string& n, int h) : MedWorker(n, "Врач"), hours(h) {}
    
    int calculateZp() const override {
        return hours * 2;
    }
    
    void display() const override {
        cout << "\nИмя: " << name << ", Должность: " << position
             << ", Отработано часов: " << hours
             << ", Доход: " << calculateZp() << " р.";
    }
};

int main() {
    Nurse nurse("Анна", 40);
    Doctor doctor("Иван", 35);

    nurse.display();
    doctor.display();

    return 0;
}