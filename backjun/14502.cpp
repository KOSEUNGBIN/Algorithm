//
// Created by 고승빈 on 2018. 8. 27..
//

#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int board[9][9];

int buildWall(int n, int m, int cnt);
int checkSize();
void infect(int n , int m, int boardTemp[][9]);

int main() {
    scanf("%d %d", &N, &M);
    for(int n = 1; n <= N; ++n) {
        for(int m = 1; m <= M; ++m) {
            scanf("%d", &board[n][m]);

        }

    }

    printf("%d\n", buildWall(1, 1, 1));
    return 0;

}

int buildWall(int n, int m, int cnt) {
    if(cnt > 3) {
        return checkSize();

    }

    int maxer = 0;
    for(int ln = n; ln <= N; ++ln) {
        for(int lm = m; lm <= M; ++lm) {
            if(board[ln][lm] == 0) {
                board[ln][lm] = 1;
                maxer = max(maxer, buildWall(n, m, cnt + 1));
                board[ln][lm] = 0;

            }

        }

    }

    return maxer;

}

int checkSize() {
    int boardTemp[9][9];
    for(int n = 0; n < 9; ++n) {
        copy(board[n], board[n] + 9, boardTemp[n]);

    }


    for(int n = 1; n <= N; ++n) {
        for(int m = 1; m <= M; ++m) {
            if(boardTemp[n][m] == 2) {
                infect(n, m, boardTemp);

            }

        }

    }

    int count = 0;
    for(int n = 1; n <= N; ++n) {
        for(int m = 1; m <= M; ++m) {
            if(boardTemp[n][m] == 0) ++count;

        }

    }

    return count;

}

void infect(int n , int m, int boardTemp[][9]) {
    if(n <= 0 || m <= 0 || n > N || m > M) return;
    if(boardTemp[n][m] == 1 || boardTemp[n][m] == 3) return;

    boardTemp[n][m] = 3;
    infect(n - 1, m, boardTemp);
    infect(n + 1, m, boardTemp);
    infect(n, m - 1, boardTemp);
    infect(n, m + 1, boardTemp);

}