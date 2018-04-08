//
// Created by 고승빈 on 2018. 4. 8..
//

#include <iostream>

using namespace std;

int main() {
    int N, L;
    int cur, start, leng = 0;
    scanf("%d %d", &N, &L);

    for (int l = L; l <= 100; ++l) {
        cur = ((l - 1) * l / 2);
        if ((N - cur) % l == 0 && (N - cur) / l >= 0) {
            start = (N - cur) / l;
            leng = l;
            break;
        }

    }

    if (leng > 0) {
        for (int i = 0; i < leng; ++i) {
            printf("%d ", start + i);
        }

        printf("\n");
    } else {
        printf("-1\n");
    }


    return 0;
}