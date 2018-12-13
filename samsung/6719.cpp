//
// Created by 고승빈 on 2018. 12. 12..
//

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        int N, K;
        cin >> N >> K;
        vector<int> arr;
        for(int n = 0; n < N; ++n) {
            int input;
            cin >> input;
            arr.push_back(input);
        }

        sort(arr.begin(), arr.end(), greater<int>());
        sort(arr.begin(), arr.begin() + K, less<int>());
        double result = 0;
        for(int k = 0; k < K; ++k) {
            result = (result + arr[k]) / 2;
        }

        cout<<fixed;
        cout.precision(6);
        cout << "#" << t << " " << result << "\n";

    }

    return 0;

}