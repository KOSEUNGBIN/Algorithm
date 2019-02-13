//
// Created by 고승빈 on 2019. 2. 13..
//

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int factorial = 1;
    for(int num = 1; num <= N; ++num) {
        factorial *= num;

    }

    cout << factorial << endl;
    return 0;

}