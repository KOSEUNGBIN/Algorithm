//
// Created by 고승빈 on 2019. 1. 9..
//

#include <iostream>
using namespace std;


int main() {
    int capacities[3];
    int state[3];

    for(int i = 0; i < 3; ++i) {
        cin >> capacities[i] >> state[i];

    }

    for(int i = 0; i < 100; ++i) {
        int cur = i % 3;
        int next = (i + 1) % 3;
        if(state[next] + state[cur] <= capacities[next]) {
            state[next] += state[cur];
            state[cur] = 0;

        } else {
            state[cur] -= capacities[next] - state[next];
            state[next] = capacities[next];

        }

    }

    for(int i = 0; i < 3; ++i) {
        cout << state[i] << "\n";

    }

    return 0;

}