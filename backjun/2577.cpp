//
// Created by 고승빈 on 2019. 1. 28..
//

#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int result = A * B * C;
    int arr[10] = { 0, };
    while(result > 0) {
        arr[(result % 10)]++;
        result /= 10;

    }

    for(int idx = 0; idx < 10; ++idx) {
        cout << arr[idx] << endl;

    }

}