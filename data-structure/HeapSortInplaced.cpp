//
// Created by 고승빈 on 2018. 6. 7..
//

#include <iostream>
#include <cmath>

using namespace std;

const int *heapSort(int arr[], int size) {
    int heapSize = (int) ceil(log2(size));
    int *heap = new int[heapSize + 1]{0,};
    int last = 1;
    int cur;
    int parent;
    int temp;
    int next;

    // make heap
    for (int i = 0; i < size; ++i) {
        heap[last] = arr[i];
        cur = last;
        parent = last / 2;
        temp = heap[cur];
        while (parent > 0) {
            if (heap[cur] > heap[parent]) {
                heap[cur] = heap[parent];
            } else {
                break;
            }

            cur = parent;
            parent /= 2;
        }

        heap[cur] = temp;
        last++;
    }

    // remove
    while (last > 1) {
        int data = heap[1];
        heap[1] = heap[last - 1];
        cur = 1;
        while (2 * cur + 1 < last) {
            if (heap[cur] >= heap[cur * 2] && heap[cur] >= heap[cur * 2 + 1]) break;

            if (heap[cur] < heap[cur * 2]) {
                temp = heap[cur];
                heap[cur] = heap[cur * 2];
                heap[cur * 2] = temp;
                next = cur * 2;
            }

            if (heap[cur] < heap[cur * 2 + 1]) {
                temp = heap[cur];
                heap[cur] = heap[cur * 2 + 1];
                heap[cur * 2 + 1] = temp;
                next = cur * 2 + 1;
            }

            cur = next;

        }

        heap[last - 1] = data;
        cout << heap[last - 1] << endl;
        last--;
    }

    return heap;
}

int main() {
    int input[8] = {10, 43, 12, 11, 42, 1, 5, 12};
    heapSort(input, 8);
    return 0;
}