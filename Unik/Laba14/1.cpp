#include <iostream>
#include <fstream>

using namespace std;

bool isUnique(int number, int uniqueNumbers[], int count) {
    for (int i = 0; i < count; ++i) {
        if (uniqueNumbers[i] == number) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream inputFile("f.txt");
    ofstream outputFile("g.txt");

    int uniqueNumbers[1000];
    int count = 0;
    int number;

    while (inputFile >> number) {
        if (isUnique(number, uniqueNumbers, count)) {
            uniqueNumbers[count] = number;
            count++;
        }
    }

    for (int i = 0; i < count; ++i) {
        outputFile << uniqueNumbers[i] << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Обработка завершена. Уникальные числа записаны в g.txt." << endl;

    return 0;
}