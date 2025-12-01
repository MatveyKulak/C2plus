#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int info;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node;
        newNode->info = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!top) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->info << " ";
            current = current->next;
        }
        cout << endl;
    }

    void removeFirstAndLast() {
        if (!top || !top->next) return;

        Node* current = top;
        Node* prev = nullptr;
        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }
        if (prev) prev->next = nullptr;
        delete current;

        pop();
    }
};

int main() {
    Stack stack;
    int n = 5;

    for (int i = 0; i < n; i++) {
        int value = rand() % 101 - 50;
        stack.push(value);
    }

    cout << "Исходный стек: ";
    stack.display();

    stack.removeFirstAndLast();

    cout << "Стек после удаления: ";
    stack.display();

    return 0;
}