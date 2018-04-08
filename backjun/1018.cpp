//
// Created by 고승빈 on 2018. 4. 8..
//

#include <iostream>

using namespace std;

typedef long long ll;
int N, M;
int wCnt, bCnt;
int minimum = 25000;
ll whitePattern = 0x00000000000000aa;
ll blackPattern = 0x0000000000000055;
ll clearPattern = 0x00000000000000ff;
ll whitePatternTrs, blackPatternTrs, clearPatternTrs;
ll board[64] = {0,};

int checkCnt(ll value) {
    int cnt = 0;
    while (value > 0) {
        if ((1 & value) == 1) {
            cnt++;
        }

        value >>= 1;
    }

    return cnt;
}

int main() {
    char ch[51];
    scanf("%d %d", &N, &M);
    for (int r = 0; r < N; ++r) {
        scanf("%s", ch);
        for (int c = 0; c < M; ++c) {
            if (ch[c] == 'B') {
                board[r] |= (1 << c);
            }

        }

    }

    for (int r = 0; r <= N - 8; ++r) {
        for (int c = 0; c <= M - 8; ++c) {
            wCnt = bCnt = 0;
            whitePatternTrs = (whitePattern << c);
            blackPatternTrs = (blackPattern << c);
            clearPatternTrs = (clearPattern << c);
            for (int i = 0; i < 8; ++i) {
                if (i % 2 == 0) {
                    wCnt += checkCnt((board[r + i] & clearPatternTrs) ^ whitePatternTrs);
                    bCnt += checkCnt((board[r + i] & clearPatternTrs) ^ blackPatternTrs);
                } else {
                    wCnt += checkCnt((board[r + i] & clearPatternTrs) ^ blackPatternTrs);
                    bCnt += checkCnt((board[r + i] & clearPatternTrs) ^ whitePatternTrs);
                }

            }

            minimum = min(minimum, min(wCnt, bCnt));
        }

    }

    printf("%d\n", minimum);
    return 0;
}
