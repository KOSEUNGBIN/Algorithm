//
// Created by 고승빈 on 2018. 10. 13..
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> predictor;
    int input;
    for(int i = 1; i <= N; ++i) {
        cin >> input;
        predictor.push_back(input);

    }

    sort(predictor.begin(), predictor.end());
    long long satisfaction = 0;
    for(int idx = 0 ; idx < predictor.size(); ++idx) {
        satisfaction += abs(predictor[idx] - (idx + 1));

    }


    cout << satisfaction << endl;
    return 0;

}