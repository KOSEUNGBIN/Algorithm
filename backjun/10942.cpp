//
// Created by 고승빈 on 2018. 4. 8..
//

#include <iostream>
#include <vector>

using namespace std;

typedef enum {
    NOTYET, PAL, NOT
} State;

int N, M;

vector<int> digit;
vector<vector<State>> memory;

bool checkPal(int start, int end) {
    if(start >= end) {
        return true;
    }

    if (memory[start][end] == PAL) {
        return true;
    } else if (memory[start][end] == NOT) {
        return false;
    } else {
        if (digit[start] != digit[end]) {
            memory[start][end] = NOT;
            return false;
        } else {
            memory[start][end] = checkPal(start + 1, end - 1) ? PAL : NOT;
            return memory[start][end] == PAL;
        }
    }

}


int main() {
    int start, end;
    scanf("%d", &N);
    digit.resize(N + 1);
    memory.assign(N + 1, vector<State>(N + 1, NOTYET));
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &digit[i]);
    }

    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &start, &end);
        printf("%d\n", checkPal(start, end));
    }

    return 0;
}