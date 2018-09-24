//
// Created by 고승빈 on 2018. 9. 24..
//

#include <iostream>
using namespace std;

typedef struct node {
    long long data;
    struct node* next;
    struct node* prev;
} Node;

class LinkedList {
private:
    Node* start;
    int count;

public:
    LinkedList() {
        start = new Node;
        start->data = 0;
        start->next = NULL;
        start->prev = NULL;

        count = 0;
    }

    void insert(long long data) {
        Node* cur = start;
        while(cur->next != NULL) {
            if (data < cur->data) {
                Node* newNode = new Node;
                newNode->data = data;
                newNode->next = cur;
                newNode->prev = cur->prev;

                cur->prev->next = newNode;
                cur->prev = newNode;

                count++;
                break;

            } else {
                cur = cur->next;

            }
        }

        if(cur->next == NULL) {
            if(cur->data < data) {
                Node *newNode = new Node;
                newNode->data = data;
                newNode->next = NULL;
                newNode->prev = cur;

                cur->next = newNode;
                count++;
            } else {
                Node* newNode = new Node;
                newNode->data = data;
                newNode->next = cur;
                newNode->prev = cur->prev;

                cur->prev->next = newNode;
                cur->prev = newNode;

                count++;

            }

        }

    }

    int search(int k) {
        Node* cur = start->next;
        for(int c = 1; c < k; ++c) {
            cur = cur->next;
        }

        return cur->data;

    }

};

int main() {
    int N, K;

    long long input;

    cin >> N >> K;
    LinkedList list;

    for(int n = 1; n <= N; ++n) {
        cin >> input;
        list.insert(input);

    }

    cout << list.search(K) << "\n";

    return 0;
}