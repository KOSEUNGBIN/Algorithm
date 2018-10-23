//
// Created by 고승빈 on 2018. 10. 23..
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool dfs(int computer, int size, vector<vector<int>>* cache) {
    bool checker = false;
    for(int com = 0; com < size; ++com) {
        if((*cache)[computer][com] == 1) {
            (*cache)[computer][com] = (*cache)[com][computer] = 0;
            checker = true;
            dfs(com, size, cache);
        }
    }

    return checker;

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<vector<int>> cache(computers);
    for(int com = 0; com < n; ++com) {
        if(dfs(com, n, &cache)) {
            answer++;

        }

    }

    return answer;

}