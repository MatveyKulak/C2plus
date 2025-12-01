/*Найдите в заданной строке наиболее часто повторяющееся слово, если
таких слов несколько выведите все*/
#include <iostream>
#include <string>

using namespace std;

void findWords() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    string words[100]; 
    int counts[100] = {0};
    int wordCount = 0;

    string currentWord;
    int maxCount = 0;

    for (char c : input) {
        if (c == ' ' || c == ',' || c == '.') {
            if (!currentWord.empty()) {
                bool found = false;
                for (int i = 0; i < wordCount; i++) {
                    if (words[i] == currentWord) {
                        counts[i]++;
                        if (counts[i] > maxCount) {
                            maxCount = counts[i];
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    words[wordCount] = currentWord;
                    counts[wordCount] = 1;
                    if (1 > maxCount) {
                        maxCount = 1;
                    }
                    wordCount++;
                }
                currentWord.clear();
            }
        } else {
            currentWord += c;
        }
    }

    if (wordCount == 0) {
        cout << "В строке нет слов." << endl;
        return;
    }

    cout << "Наиболее часто встречающиеся слова (" << maxCount << " раз):" << endl;
    for (int i = 0; i < wordCount; i++) {
        if (counts[i] == maxCount) {
            cout << words[i] << endl;
        }
    }
}

int main() {
    findWords();
    return 0;
}