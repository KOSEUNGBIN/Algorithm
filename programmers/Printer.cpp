//
// Created by 고승빈 on 2019. 1. 21..
//

#include <iostream>
#include <vector>

#define MAX_SIZE 500
using namespace std;

class Queue {
private:
    int size;
    int front;
    int rear;
    int nodes[MAX_SIZE];

public:
    Queue() {
        size = 0;
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(int value) {
        nodes[rear] = value;
        rear = (rear + 1) % MAX_SIZE;
        size++;

    }

    int pop() {
        int value = nodes[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        return value;
    }

    bool isFrontLargest(int value) {
        for (int idx = front; idx != rear - 1; idx = (idx + 1) % MAX_SIZE) {
            if (value < nodes[idx]) {
                return false;

            }

        }

        return true;

    }

    int getSize() {
        return size;

    }

};

int countPriority(Queue &queue, int location) {
    int count = 1;
    int currentLocation = location;
    while (!queue.isEmpty()) {
        int value = queue.pop();
        if (queue.isFrontLargest(value)) {
            if (currentLocation == 0) {
                break;

            }

            count++;

        } else {
            queue.push(value);

        }

        currentLocation--;
        if (currentLocation < 0) {
            currentLocation = queue.getSize() - 1;

        }

    }

    return count;

}

int solution(vector<int> priorities, int location) {
    Queue queue;
    for (int p : priorities) {
        queue.push(p);

    }

    return countPriority(queue, location);

}

int main() {
    vector<int> priorities = {2, 1, 3, 2};
    int location = 2;
    cout << solution(priorities, location) << endl;
    return 0;

}