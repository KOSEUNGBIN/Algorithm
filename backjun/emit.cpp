//
// Created by 고승빈 on 2018. 3. 30..
//

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int T;
    int subsetB[1000001];
    unsigned char A[3750000];
    int N ;
    int count;
    int input;

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);
        memset(A, 0x00, 3750000);
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &input);
            A[input / 8] |= 1 << (input % 8);
        }

        count = 0;
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &input);

            if((A[input / 8] & (1 << input % 8)) == 0) {
                subsetB[count++] = input;
            }
        }

        for (int i = 0; i < count; ++i) {
            printf("%d ", subsetB[i]);
        }

        if(count == 0) {
            printf("0");
        }

        printf("\n");
    }
    return 0;
}