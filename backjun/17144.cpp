//
// Created by 고승빈 on 2019-05-07.
//

#include <iostream>

#define MAX_SECOND 1001
#define MAX_LENGTH 50
#define MAX_DIRECT 4
#define SPREAD_RATIO 5

using namespace std;

int room[MAX_SECOND][MAX_LENGTH][MAX_LENGTH];

int dr[MAX_DIRECT] = {1, -1, 0, 0};
int dc[MAX_DIRECT] = {0, 0, 1, -1};

bool isPossible(int second, int r, int c, int R, int C) {
    return (0 <= r && r < R) && (0 <= c && c < C) && (room[second][r][c] >= 0);

}

int tryMove(int second, int r, int c, int R, int C) {
    int prev = second - 1;
    int count = 0;
    for (int direct = 0; direct < MAX_DIRECT; ++direct) {
        int aroundR = r + dr[direct];
        int aroundC = c + dc[direct];
        if (isPossible(prev, aroundR, aroundC, R, C)) {
            room[second][aroundR][aroundC] += room[prev][r][c] / SPREAD_RATIO;
            count++;

        }

    }

    return count;

}

void spread(int second, int R, int C) {
    int prev = second - 1;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (room[prev][r][c] >= 0) {
                room[second][r][c] +=
                        room[prev][r][c] - ((room[prev][r][c] / SPREAD_RATIO) * tryMove(second, r, c, R, C));

            } else {
                room[second][r][c] = -1;

            }

        }

    }

}

void clean(int second, int start, int end, int R, int C) {
    // left
    for (int leftR = start - 1; leftR >= 0; --leftR) {
        room[second][leftR + 1][0] = room[second][leftR][0];

    }

    for (int leftR = end + 1; leftR < R; ++leftR) {
        room[second][leftR - 1][0] = room[second][leftR][0];

    }

    // top
    for (int c = 1; c < C; ++c) {
        room[second][0][c - 1] = room[second][0][c];
        room[second][R - 1][c - 1] = room[second][R - 1][c];

    }

    // right
    for (int rightR = 1; rightR <= start; ++rightR) {
        room[second][rightR - 1][C - 1] = room[second][rightR][C - 1];

    }

    for (int rightR = R - 2; rightR >= end; --rightR) {
        room[second][rightR + 1][C - 1] = room[second][rightR][C - 1];

    }

    // bottom
    for (int c = C - 1; c > 0; --c) {
        room[second][start][c] = room[second][start][c - 1];
        room[second][end][c] = room[second][end][c - 1];

    }

    // clean & reset
    room[second][start][0] = room[second][end][0] = -1;
    room[second][start][1] = room[second][end][1] = 0;

}

long long dirtyAmount(int second, int R, int C) {
    long long amount = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            amount += (room[second][r][c] >= 0 ? room[second][r][c] : 0);

        }

    }

    return amount;

}

int findAirMachine(int R) {
    for (int r = 0; r < R; ++r) {
        if (room[0][r][0] < 0) {
            return r;

        }

    }

    return -1; // error

}

void display(int second, int R, int C) {
    cout << "second ) " << second << endl;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cout << room[second][r][c] << " ";

        }

        cout << endl;

    }

    cout << endl;

}

int main() {
    int R, C, T;
    cin >> R >> C >> T;

    int initSecond = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> room[initSecond][r][c];

        }

    }

    int airMachineStart = findAirMachine(R);
    int airMachineEnd = airMachineStart + 1;
    for (int second = 1; second <= T; ++second) {
        spread(second, R, C);
        clean(second, airMachineStart, airMachineEnd, R, C);
//        display(second, R, C);

    }

    cout << dirtyAmount(T, R, C) << endl;
    return 0;

}