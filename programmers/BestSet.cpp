//
// Created by 고승빈 on 2019. 1. 5..
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



vector<int> solution(int n, int s) {
    vector<int> data;
    int m = s / n;
    int rest = s % n;
    if (s > n) {
        for (int idx = rest; idx < n; ++idx) {
            data.push_back(m);
        }

        for (int idx = 0; idx < rest; ++idx) {
            data.push_back(m + 1);

        }

    } else {
        data.push_back(-1);

    }


    return data;

}

int main() {
    vector<int> result = solution(2, 1);
    for (int v : result) {
        cout << v << endl;

    }

    return 0;

}