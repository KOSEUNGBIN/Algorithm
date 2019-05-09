//
// Created by 고승빈 on 2019-05-06.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define MAX_BIRUS_COUNT 10
#define MAX_LENGTH 50
#define MAX_VALUE 2500
#define MAX_DIRECTION 4

using namespace std;

int room[MAX_BIRUS_COUNT][MAX_LENGTH][MAX_LENGTH];

int dx[MAX_DIRECTION] = {1, -1, 0, 0};
int dy[MAX_DIRECTION] = {0, 0, 1, -1};

class Node {
private :
    int y;
    int x;
    int count;

public:
    Node(int y, int x, int count) {
        this->y = y;
        this->x = x;
        this->count = count;

    }

    int getX() {
        return x;

    }

    int getY() {
        return y;

    }

    int getCount() {
        return count;

    }

};

void trace(int birus, int row, int column, int n) {
    queue<Node *> que;
    que.push(new Node(row, column, 0));
    while (!que.empty()) {
        Node *spot = que.front();
        for (int dir = 0; dir < MAX_DIRECTION; ++dir) {
            int nextY = spot->getY() + dy[dir];
            int nextX = spot->getX() + dx[dir];
            if (!(nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)) {
                if (room[birus][nextY][nextX] == 0 || room[birus][nextY][nextX] == -2) {
                    room[birus][nextY][nextX] = spot->getCount() + 1;
                    que.push(new Node(nextY, nextX, room[birus][nextY][nextX]));

                }

            }

        }

        que.pop();

    }


}

void copy(int source[MAX_LENGTH][MAX_LENGTH], int dest[MAX_LENGTH][MAX_LENGTH], int n) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            dest[r][c] = source[r][c];

        }

    }

}

void copyBirus(int state[MAX_LENGTH][MAX_LENGTH], int n, int count) {
    for (int b = 0; b < count; ++b) {
        copy(state, room[b], n);

    }

}

void merge(int state[MAX_LENGTH][MAX_LENGTH], int birus, int n) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (state[r][c] == 0 || (room[birus][r][c] != 0 && room[birus][r][c] < state[r][c])) {
                state[r][c] = room[birus][r][c];

            }

        }

    }

}

bool isInvalid(int state[MAX_LENGTH][MAX_LENGTH], int n) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (state[r][c] == 0) {
                return true;

            }

        }

    }

    return false;

}

int findMax(int state[MAX_LENGTH][MAX_LENGTH], int n) {
    int maximum = 0;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (maximum < state[r][c]) {
                maximum = state[r][c];

            }

        }

    }

    return maximum;

}

int find(int state[MAX_LENGTH][MAX_LENGTH], int birus, int birusLimit, int count, int limit, int n) {
    if (count >= limit) {
        // 가능한 경우 인지 확인 --> 가능하지 않으면 음수 반환
        if (isInvalid(state, n)) {
            return -1;

        }

        // 최대 값 반환
        return findMax(state, n);

    }

    int minimum = MAX_VALUE;
    for (int next = birus; next < birusLimit; ++next) {
        int nextState[MAX_LENGTH][MAX_LENGTH];
        copy(state, nextState, n);
        merge(nextState, next, n);

        int ret = find(nextState, next + 1, birusLimit, count + 1, limit, n);
        if (ret >= 0 && ret < minimum) {
            minimum = ret;

        }

    }

    return minimum == MAX_VALUE ? -1 : minimum;

}

void display(int count, int n) {
    for (int b = 0; b < count; ++b) {
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                cout << room[b][r][c] << " ";

            }

            cout << endl;

        }

        cout << endl;

    }

}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> birusPositions;
    int state[MAX_LENGTH][MAX_LENGTH];
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> state[r][c];
            if (state[r][c] == 2) {
                birusPositions.push_back(make_pair(r, c));

            }

            state[r][c] *= -1;

        }

    }

    int birusCount = birusPositions.size();
    copyBirus(state, N, birusCount);

    for (int birus = 0; birus < birusCount; ++birus) {
        trace(birus, birusPositions[birus].first, birusPositions[birus].second, N);

    }

//    display(birusCount, N);
    cout << find(state, 0, birusCount, 0, M, N) << endl;

    return 0;

}