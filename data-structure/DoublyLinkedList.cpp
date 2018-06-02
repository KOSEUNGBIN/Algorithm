//
// Created by 고승빈 on 2018. 6. 2..
//

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* prev = NULL;
    struct Node* next = NULL;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    DoublyLinkedList();
    Node* first();
    Node* end();
    void pushFront(int data);
    void pushBack(int data);
    void remove(Node* node);
    void display();
};

DoublyLinkedList::DoublyLinkedList() {
    this->head = new Node();
    this->tail = new Node();
    this->head->next = this->tail;
    this->tail->prev = this->head;
    this->size = 0;
}

Node *DoublyLinkedList::first() {
    return this->head->next;
}

Node *DoublyLinkedList::end() {
    return this->tail->prev;
}

void DoublyLinkedList::pushFront(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = this->head->next;
    newNode->prev =  this->head;
    this->head->next->prev = newNode;
    this->head->next = newNode;
    this->size++;
}

void DoublyLinkedList::pushBack(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = this->tail;
    newNode->prev =  this->tail->prev;
    this->tail->prev->next = newNode;
    this->tail->prev = newNode;
    this->size++;
}

void DoublyLinkedList::remove(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    this->size--;
}

void DoublyLinkedList::display() {
    cout << "size: " << this->size << endl;
    Node *cur = this->first();
    while (cur != this->tail) {
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl;
}

int main()
{
    int input;
    int data;

    DoublyLinkedList list;
    cout << "input: ";
    cin >> input;
    while (input > 0) {
        switch (input) {
            case 1 : {
                cin >> data;
                list.pushFront(data);
                break;
            }
            case 2 : {
                cin >> data;
                list.pushBack(data);
                break;
            }
            case 3 : {
                cin >> data;
                Node *first = list.first();
                while (first != NULL && first->data != data) {
                    first = first->next;
                }

                if (first == NULL) {
                    cout << data << " 는 존재하지 않습니다." << endl;
                    break;
                }

                list.remove(first);
                break;
            }
            case 4 : {
                list.display();
                break;
            }
        }

        cout << "input: ";
        cin >> input;
    }

    return 0;
}