//
// Created by 고승빈 on 2019. 1. 29..
//

#define MAX_SIZE 100

#include <iostream>

using namespace std;

int main() {
    int N, M;
    char board[MAX_SIZE][MAX_SIZE];
    cin >> N >> M;
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            cin >> board[n][m];

        }

    }

    int count = 0;
    for (int n = 0; n < N; ++n) {
        int m = 0;
        char before = '|';
        while (m < M) {
            if (before == '|' && board[n][m] == '-') {
                count++;

            }

            before = board[n][m];
            m++;

        }

    }

    for (int m = 0; m < M; ++m) {
        int n = 0;
        char before = '-';
        while (n < N) {
            if (before == '-' && board[n][m] == '|') {
                count++;

            }

            before = board[n][m];
            n++;

        }

    }

    cout << count << endl;
    return 0;

}

//  4 4
//  ----
//  ----
//  ----
//  ----
//
//  4 4
//  ||||
//  ||||
//  ||||
//  ||||
//
//  4 4
//  -|-|
//  |-|-
//  -|-|
//  |-|-