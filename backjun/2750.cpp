//
// Created by 고승빈 on 2018. 6. 8..
//

#include <iostream>
using namespace std;

void bubbleSort(int *input, int size) {
    int limit;
    int temp;
    for(int i = 0; i < size; ++i) {
        limit = size - i - 1;
        for(int j = 0; j < limit; ++j) {
            if(input[j] > input[j + 1]) {
                temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int *input, int size) {
    int maximumIndex;
    int temp;
    for(int i = 0; i < size; ++i) {
        maximumIndex = size - i - 1;
        for(int j = 0; j < size - i - 1; ++j) {
            if(input[j] > input[maximumIndex]) {
                maximumIndex = j;
            }
        }

        temp = input[maximumIndex];
        input[maximumIndex] = input[size - i - 1];
        input[size - i - 1] = temp;
    }
}

void insertionSort(int *input, int size) {
    int cur;
    int data;
    for(int i = 1; i < size; ++i) {
        cur = i;
        data = input[cur];
        while(--cur >= 0 && input[cur] > data) {
            input[cur + 1] = input[cur];
        }

        input[cur + 1] = data;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int input[N];
    for(int i = 0 ; i < N; ++i) {
        scanf("%d", &input[i]);
    }

    insertionSort(input, N);
    for(int i = 0 ; i < N; ++i) {
        printf("%d\n", input[i]);
    }

    return 0;
}