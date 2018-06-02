//
// Created by 고승빈 on 2018. 6. 2..
//

#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(int start, int end, int data, int cards[]) {
    if(start > end) return false;
    int mid = (start + end) / 2;
    if(cards[mid] == data) return true;
    else if(cards[mid] > data) return binarySearch(start, mid - 1, data, cards);
    else return binarySearch(mid + 1, end, data, cards);
}

int main() {
    int N, M, num;
    scanf("%d", &N);
    int card[N];
    for(int i = 0; i < N; ++i) {
        scanf("%d", &card[i]);
    }

    scanf("%d", &M);
    sort(card, card + N);
    while(M--) {
        scanf("%d", &num);
        printf("%d ", binarySearch(0, N, num, card) ? 1 : 0);
    }

    printf("\n");
    return 0;
}