//
// Created by 고승빈 on 2018. 10. 4..
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int directionX[4] = { 1, -1, 0, 0 };
int directionY[4] = { 0, 0, 1, -1 };

void bfs(pair<int, int>* node, vector<vector<bool>>* circuit, vector<vector<bool>>* cache, queue<pair<int, int>>* que, int lastRow, int lastColumn) {
    for(int idx = 0; idx < 4; ++idx) {
        bool isNotOutOfRange = !(node->first + directionX[idx] <= 0 || node->first + directionX[idx] > lastColumn || node->second + directionY[idx] <= 0 || node->second + directionY[idx] > lastRow);
        if(isNotOutOfRange) {
            bool isPercolate = (*circuit)[node->second + directionY[idx]][node->first + directionX[idx]];
            bool isPass = (*cache)[node->second + directionY[idx]][node->first + directionX[idx]];
            if(!isPercolate && !isPass) {
                (*cache)[node->second + directionY[idx]][node->first + directionX[idx]] = true;
                pair<int, int> sol = make_pair(node->first + directionX[idx], node->second + directionY[idx]);
                que->push(sol);

            }

        }

    }

}

bool search(vector<vector<bool>> circuit, int x, int y, int lastRow, int lastColumn) {
    if(circuit[y][x]) return false;
    pair<int, int> node;
    node.first = x;
    node.second = y;

    vector<vector<bool>> cache;
    cache.assign(lastRow + 1, vector<bool>(lastColumn + 1, false));
    cache[y][x] = true;

    queue<pair<int, int>> que;
    que.push(node);
    while(!que.empty()) {
        pair<int, int> cur = que.front();
        if(cur.second >= lastRow) {
            return true;

        }

        bfs(&cur, &circuit, &cache, &que, lastRow, lastColumn);
        que.pop();

    }

    return false;

}

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<bool>> circuit;
    circuit.assign(M + 1, vector<bool>(N + 1, false));

    char input;
    for(int r = 1; r <= M; ++r) {
        for(int c = 1; c <= N; ++c) {
            cin >> input;
            circuit[r][c] = (input == '1');

        }

    }

    for(int c = 1; c <= N; ++c) {
        if(search(circuit, c, 1, M, N)) {
            cout << "YES" << "\n";
            return 0;
        }
    }

    cout << "NO" << "\n";


    return 0;

}