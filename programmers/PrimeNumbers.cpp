//
// Created by 고승빈 on 2019. 1. 7..
//

#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

void sign(bool *cache, ll number, int N) {
    for (ll idx = number * number; idx <= N; idx += number) {
        cache[idx] = false;

    }

}


ll solution(int N) {
    long long answer = 0;

    /* 에라토스테네스의 체 */
    bool *cache = new bool[N + 1];
    fill(cache, cache + N + 1, 1);

    for (ll n = 2; n <= N; ++n) {
        if (cache[n]) {
            answer += n;
            sign(cache, n, N);

        }

    }

    return answer;

}

int main() {
    cout << solution(7) << endl;
    cout << solution(8) << endl;
    cout << solution(2) << endl;

    return 0;

}