//
// Created by 고승빈 on 2019-03-15.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;

    cout << L - max(ceil((double) A / C), ceil((double) B / D)) << endl;
    return 0;

}