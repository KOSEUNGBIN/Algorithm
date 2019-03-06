//
// Created by 고승빈 on 2019-03-06.
//

#include <iostream>
#include <vector>
#include <cmath>

#define MAX_SIZE 20
#define MAX_VALUE 200000

using namespace std;

int give(int power[MAX_SIZE][MAX_SIZE], vector<int> team) {
    int teamPower = 0;
    for (int me : team) {
        for (int other : team) {
            teamPower += power[me][other];

        }

    }

    return teamPower;

}

vector<int> makeOtherTeam(vector<bool> &visit) {
    vector<int> team;
    for (int idx = 0; idx < visit.size(); ++idx) {
        if (!visit[idx]) {
            team.push_back(idx);

        }

    }

    return team;

}

int tryTracking(vector<int> &team, vector<bool> &visit, int index, int limit, int power[MAX_SIZE][MAX_SIZE]) {
    if (team.size() >= limit / 2) {  // 종료 조건
        return abs(give(power, team) - give(power, makeOtherTeam(visit)));

    }

    int minimum = MAX_VALUE;
    for (int start = index; start < limit; ++start) {
        visit[start] = true;
        team.push_back(start);
        minimum = min(minimum, tryTracking(team, visit, start + 1, limit, power));
        visit[start] = false;
        team.pop_back();

    }

    return minimum;

}

int difference(int power[MAX_SIZE][MAX_SIZE], int N) {
    vector<int> team;
    vector<bool> visit(N, false);
    return tryTracking(team, visit, 0, N, power);

}

int main() {
    int N;
    cin >> N;

    int power[MAX_SIZE][MAX_SIZE];
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> power[row][col];

        }

    }

    cout << difference(power, N) << "\n";
    return 0;

}