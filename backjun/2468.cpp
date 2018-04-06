//
// Created by 고승빈 on 2018. 4. 7..
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;


priority_queue<int, vector<int>, greater<int>> height;
vector<vector<int>> lands;
vector<vector<int>> memory;


bool dfs(int row, int col, int N, int curHeight) {
    if(row < 0 || row >= N || col < 0 || col >= N) {
        return false;
    }

    if(memory[row][col] < 0) {
        return false;
    }

    if(memory[row][col] == curHeight) {
        return false;
    }

    memory[row][col] = curHeight;
    if(lands[row][col] <= curHeight) {
        memory[row][col] = -1;
        return false;
    }

    bool result = true;
    result |= dfs(row + 1, col, N, curHeight);
    result |= dfs(row - 1, col, N, curHeight);
    result |= dfs(row, col + 1, N, curHeight);
    result |= dfs(row, col - 1, N, curHeight);
    return result;
}

int main() {
    int N;
    int curHeight, count, maximum = 1000;
    scanf("%d", &N);
    lands.assign(N, vector<int>(N));

    for(int r = 0; r < N; ++r) {
        for(int c = 0; c < N; ++c) {
            scanf("%d", &lands[r][c]);
            height.push(lands[r][c]);
            maximum = min(maximum, lands[r][c]);
        }
    }

    memory.assign(N, vector<int>(N, 0));
    while(!height.empty()) {
        count = 0;
        curHeight = height.top();
        for(int r = 0; r < N; ++r) {
            for(int c = 0; c < N; ++c) {
                if(dfs(r, c, N, curHeight)){
                    count++;
                }
            }
        }

        maximum = max(maximum, count);
        height.pop();
    }

    printf("%d", maximum);

    return 0;
}