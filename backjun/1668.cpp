//
// Created by 고승빈 on 2018. 9. 14..
//

#include <iostream>
using namespace std;

int main() {
    int N;
    int arr[51];

    cin >> N;
    for(int n = 1; n <= N; ++n) {
        cin >> arr[n];

    }

    int leftCount = 1;
    int rightCount = 1;
    int leftMaximum = arr[1];
    int rightMaximum = arr[N];

    for(int idx = 2; idx <= N; ++idx) {
        if(leftMaximum < arr[idx]) {
            leftMaximum = arr[idx];
            ++leftCount;

        }

        if(rightMaximum < arr[N - idx + 1]) {
            rightMaximum = arr[N - idx + 1];
            ++rightCount;

        }

    }

    cout << leftCount << "\n" << rightCount << "\n";

    return 0;

}
