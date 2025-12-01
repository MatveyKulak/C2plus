#include <iostream>

using namespace std;

struct Node {
    int info;
    Node* next;
};

class Queue {
    Node* begin;
    Node* end;

public:
    Queue() : begin(nullptr), end(nullptr) {}

    void push(int value) {
        Node* newNode = new Node{value, nullptr};
        if (end) {
            end->next = newNode;
        }
        end = newNode;
        if (!begin) {
            begin = newNode;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Очередь пуста!" << endl;
            return;
        }
        Node* temp = begin;
        begin = begin->next;
        delete temp;
        if (!begin) {
            end = nullptr;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Очередь пуста!" << endl;
            return -1;
        }
        return begin->info;
    }

    void queuelist() {
        if (isEmpty()) {
            cout << "Очередь пуста!" << endl;
            return;
        }
        Node* temp = begin;
        while (temp) {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return begin == nullptr;
    }
};

int main() {
    Queue queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    cout << "Элементы очереди: ";
    queue.queuelist();
    cout << "Первый элемент: " << queue.peek() << endl;
    queue.pop();
    cout << "Элементы очереди после удаления: ";
    queue.queuelist();
    return 0;
}