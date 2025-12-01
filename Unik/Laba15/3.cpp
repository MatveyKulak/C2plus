#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int info;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    Node* begin;
    Node* end;

public:
    DoublyLinkedList() : begin(nullptr), end(nullptr) {}

    void addNode(int value) {
        Node* newNode = new Node;
        newNode->info = value;
        newNode->prev = end;
        newNode->next = nullptr;

        if (begin == nullptr) {
            begin = newNode;
        } else {
            end->next = newNode;
        }
        end = newNode;
    }

    void display() {
        Node* current = begin;
        while (current != nullptr) {
            cout << current->info << " ";
            current = current->next;
        }
        cout << endl;
    }

    void swapFirstWithMax() {
        if (begin == nullptr || begin->next == nullptr) return;

        Node* maxNode = begin;
        Node* current = begin->next;
        
        while (current != nullptr) {
            if (current->info > maxNode->info) {
                maxNode = current;
            }
            current = current->next;
        }

        if (maxNode == begin) return;

        int temp = begin->info;
        begin->info = maxNode->info;
        maxNode->info = temp;
    }
};

int main() {
    DoublyLinkedList list;
    int n = 5;

    for (int i = 0; i < n; i++) {
        int value = rand() % 101 - 50;
        list.addNode(value);
    }

    cout << "Исходный список: ";
    list.display();

    list.swapFirstWithMax();

    cout << "Список после замены: ";
    list.display();

    return 0;
}