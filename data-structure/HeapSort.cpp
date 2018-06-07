//
// Created by 고승빈 on 2018. 6. 4..
//

#include <iostream>
using namespace std;

class Heap {
private:
    int arr[100] = {0, };
    int size = 1;
public:
    void insert(int data);
    void remove();
    void travelsalInorder(int cur, int depth);
};

// up heap
void Heap::insert(int data) {
    int lastNode = size;
    arr[lastNode] = data;
    ++size;

    int cur = lastNode;
    int parent = cur / 2;
    int temp;
    while(parent > 0) {
        if(arr[cur] > arr[parent]) {
            temp = arr[cur];
            arr[cur] = arr[parent];
            arr[parent] = temp;
        } else {
            break;
        }

        cur = parent;
        parent /= 2;
    }
}

// down heap
void Heap::remove() {
    int cur = 1;
    int next;
    arr[1] = arr[size - 1];
    arr[size] = 0;
    size--;
    int temp;
    while(cur * 2 + 1  <= size) {
        if(heap[cur] >= heap[cur * 2] && heap[cur] >= heap[cur * 2 + 1])
            break;

        if(arr[cur] < arr[cur * 2]) {
            temp = arr[cur];
            arr[cur] = arr[cur * 2];
            arr[cur * 2] = temp;
            next = cur * 2;
        }

        if(arr[cur] < arr[cur * 2 + 1]) {
            temp = arr[cur];
            arr[cur] = arr[cur * 2 + 1];
            arr[cur * 2 + 1] = temp;
            next = cur * 2 + 1;
        }

        next = cur;
    }

}

void Heap::travelsalInorder(int cur, int depth) {
    if(cur >= size) return;
    travelsalInorder(cur * 2, depth + 1);
    cout << cur << " = " << arr[cur] << " , depth = " << depth << endl;
    travelsalInorder(cur * 2 + 1, depth + 1);
}

int main() {
    Heap heap;
    for(int i = 10; i > 0 ; --i) {
        heap.insert(i);
    }

    for(int i = 1; i < 10 ; ++i) {
        if(i % 2 == 0) continue;
        heap.remove();
    }

    heap.travelsalInorder(1, 0);
    return 0;
}



