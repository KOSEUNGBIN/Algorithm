//
// Created by 고승빈 on 2018. 5. 31..
// 단방향 링크드 리스트

#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

class LinkedList {
private:
    Node *head;
    int size;
public:
    LinkedList();

    void remove(Node *node);

    void push(int data);

    Node *first();

    void display();

};

LinkedList::LinkedList() {
    Node *dummyNode = new Node();
    dummyNode->data = 0;
    dummyNode->next = NULL;
    this->head = dummyNode;
    this->size = 0;
}

void LinkedList::push(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = this->head->next;
    this->head->next = newNode;
    this->size++;
}

void LinkedList::remove(Node *node) {
    Node *cur = this->head;
    while (cur != NULL && cur->next != node) {
        cur = cur->next;
    }

    if (cur == NULL) return;
    cur->next = node->next;
    this->size--;
}

Node *LinkedList::first() {
    return this->head->next;
}

void LinkedList::display() {
    cout << "size: " << this->size << endl;
    Node *cur = this->first();
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl;
}


int main() {
    int input;
    int data;

    LinkedList list;
    cout << "input: ";
    cin >> input;
    while (input > 0) {
        switch (input) {
            case 1 : {
                cin >> data;
                list.push(data);
                break;
            }
            case 2 : {
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
            case 3 : {
                list.display();
                break;
            }
        }

        cout << "input: ";
        cin >> input;
    }

    return 0;
}
