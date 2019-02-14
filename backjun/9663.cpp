//
// Created by 고승빈 on 2019. 2. 14..
//

#include <iostream>

#define MAX_SIZE 50
#define DIRECTION_SIZE 3

using namespace std;

int dx[DIRECTION_SIZE] = {-1, 0, 1};

bool isInner(int co, int N) {
    return 0 <= co && co < N;

}

bool isOutter(int co, int N) {
    return !isInner(co, N);

}

bool isImpossible(bool board[MAX_SIZE][MAX_SIZE], int N, int y, int x, int mx) {
    if (isOutter(y, N) || isOutter(x, N)) { return false; }
    return board[y][x] || isImpossible(board, N, y - 1, x + mx, mx);

}

bool isImpossible(bool board[MAX_SIZE][MAX_SIZE], int N, int y, int x) {
    for (int mx : dx) {
        if (isImpossible(board, N, y - 1, x + mx, mx)) {
            return true;

        }

    }

    return false;

}

int trace(bool board[MAX_SIZE][MAX_SIZE], int N, int y) {
    if (isOutter(y, N)) {
        return 1;

    }

    int count = 0;
    for (int x = 0; x < N; ++x) {
        if (isImpossible(board, N, y, x)) {
            continue;

        }

        board[y][x] = true;
        int tem = trace(board, N, y + 1);
        count += tem;
        board[y][x] = false;

    }

    return count;

}

int entry(bool board[MAX_SIZE][MAX_SIZE], int N) {
    int count = 0;
    int half = (N / 2) + (N % 2);
    for (int x = 0; x < half; ++x) {
        board[0][x] = true;
        int result = trace(board, N, 1);
        count += (N % 2 == 1 && x == half - 1) ? result : 2 * result;
        board[0][x] = false;

    }

    return count;

}


int main() {
    for (int t = 1; t < 15; ++t) {
        int N = t;
        bool board[MAX_SIZE][MAX_SIZE];
        cout << "N = " << t << " " << entry(board, N) << endl;

    }

    return 0;

}