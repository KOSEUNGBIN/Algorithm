//
// Created by 고승빈 on 2019-05-06.
//

#include <iostream>
#include <queue>
#include <utility>

#define MAX_POPULATION_PER_COUNT 50
#define MAX_DIRECTION 4

using namespace std;

int dy[MAX_DIRECTION] = {-1, 1, 0, 0};
int dx[MAX_DIRECTION] = {0, 0, -1, 1};

int average(int map[MAX_POPULATION_PER_COUNT][MAX_POPULATION_PER_COUNT],
            int visit[MAX_POPULATION_PER_COUNT][MAX_POPULATION_PER_COUNT], int counter, int y, int x, int N, int L,
            int R) {
    int count = 1;
    int sum = map[y][x];
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    while (!que.empty()) {
        pair<int, int> co = que.front();
        for (int dir = 0; dir < MAX_DIRECTION; ++dir) {
            int nextY = co.first + dy[dir];
            int nextX = co.second + dx[dir];
            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N) {
                int diff = abs(map[nextY][nextX] - map[co.first][co.second]);
                if (visit[nextY][nextX] == 0 && L <= diff && diff <= R) {
                    visit[nextY][nextX] = counter;
                    ++count;
                    sum += map[nextY][nextX];
                    que.push(make_pair(nextY, nextX));

                }

            }

        }

        que.pop();

    }

    return sum / count;

}

void fair(int map[MAX_POPULATION_PER_COUNT][MAX_POPULATION_PER_COUNT],
          int visit[MAX_POPULATION_PER_COUNT][MAX_POPULATION_PER_COUNT],
          vector<int> counterContainer, int N) {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            map[y][x] = counterContainer[visit[y][x] - 1];

        }

    }

}

void clear(int visit[MAX_POPULATION_PER_COUNT][MAX_POPULATION_PER_COUNT], int N) {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            visit[y][x] = 0;

        }

    }

}

int move(int map[MAX_POPULATION_PER_COUNT][MAX_POPULATION_PER_COUNT], int N, int L, int R) {
    int limit = N * N;
    int round = 0;
    vector<int> counterContainer;
    do {
        int counter = 1;
        int visit[MAX_POPULATION_PER_COUNT][MAX_POPULATION_PER_COUNT];
        clear(visit, N);
        counterContainer.clear();
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                if (!visit[y][x]) {
                    visit[y][x] = counter;
                    int avg = average(map, visit, counter, y, x, N, L, R);
                    counterContainer.push_back(avg);
                    ++counter;

                }

            }

        }

        fair(map, visit, counterContainer, N);
        if (counterContainer.size() < limit) { ++round; }

    } while (counterContainer.size() < limit);
    return round;

}

int main() {
    ios::sync_with_stdio(false);
    int N, L, R;
    cin >> N >> L >> R;

    int map[MAX_POPULATION_PER_COUNT][MAX_POPULATION_PER_COUNT];
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> map[y][x];

        }

    }

    cout << move(map, N, L, R) << endl;
    return 0;

}