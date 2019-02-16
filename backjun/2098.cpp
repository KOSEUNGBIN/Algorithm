//
// Created by 고승빈 on 2019. 2. 15..
//

#include <iostream>

#define MAX_SIZE 16
#define MAX_VALUE 16000001
#define MAX_CACHE_SIZE 65536

using namespace std;

int recSearch(int cost[MAX_SIZE][MAX_SIZE], int cache[MAX_SIZE][MAX_CACHE_SIZE], int N, int row, int mask, int last) {
    if (mask >= last) {
        return cost[row][0] != 0 ? cost[row][0] : MAX_VALUE;

    }

    if (cache[row][mask] > 0) {
        return cache[row][mask];

    }

    int minimum = MAX_VALUE;
    for (int to = 1; to < N; ++to) {
        int visit = 1 << to;
        if (((mask & visit) == 0) && (cost[row][to] != 0)) {
            int temp = recSearch(cost, cache, N, to, (mask | visit), last) + cost[row][to];
            if (temp < minimum) {
                minimum = temp;

            }

        }

    }

    return cache[row][mask] = minimum;

}

void init(int cache[MAX_SIZE][MAX_CACHE_SIZE]) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_CACHE_SIZE; ++j) {
            cache[i][j] = 0;

        }

    }

}

int main() {
    int N;
    scanf("%d", &N);
    int cost[MAX_SIZE][MAX_SIZE];
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            scanf("%d", &cost[y][x]);

        }

    }

    int cache[MAX_SIZE][MAX_CACHE_SIZE];
    init(cache);
    printf("%d\n", recSearch(cost, cache, N, 0, 1, (1 << N) - 1));
    return 0;

}