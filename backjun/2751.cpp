//
// Created by 고승빈 on 2018. 6. 9..
//

#include <iostream>
#include <cmath>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main() {
    int N, size, *arr, input;
    int last = 1, cur, parent, temp, next, nextTmp;
    scanf("%d", &N);
    size = (int) pow(2, ceil(log2(N)));
    arr = new int[size];
    memset(arr, -1, size*sizeof(int));
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &input);
        arr[last] = input;
        cur = last;
        parent = cur / 2;
        while(parent >= 1) {
            if(arr[cur] > arr[parent]) {
                temp = arr[parent];
                arr[parent] = arr[cur];
                arr[cur] = temp;
            } else {
                break;
            }

            cur = parent;
            parent = cur / 2;
        }

        last++;
    }

    last--;
    for(int i = last; i > 0 ; --i) {
        temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        next = cur = 1;
        bool check;
        while(cur < i) {
            check = false;
            if((2 * cur <  i) && (arr[2 * cur] >= 0) && (arr[cur] < arr[2 * cur])) {
                nextTmp = arr[2 * cur];
                arr[2 * cur] = arr[cur];
                arr[cur] = nextTmp;
                next = 2 * cur;
                check = true;
            }

            if((2 * cur + 1 < i) && (arr[2 * cur + 1] >= 0) && (arr[cur] < arr[2 * cur + 1])) {
                nextTmp = arr[2 * cur + 1];
                arr[2 * cur + 1] = arr[cur];
                arr[cur] = nextTmp;
                if(check) {
                    nextTmp = arr[2 * cur];
                    arr[2 * cur] = arr[2 * cur + 1];
                    arr[2 * cur + 1] = nextTmp;
                }

                next = 2 * cur + 1;
            }

            if(next == cur) break;

            cur = next;
        }


    }

    for(int i = 1; i <= N; ++i) {
        printf("%d\n", arr[i]);
    }

    return 0;
}