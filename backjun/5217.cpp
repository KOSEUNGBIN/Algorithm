//
// Created by 고승빈 on 2018. 10. 3..
//

#include <iostream>
using namespace std;

void checkAndPrint(int n) {
    cout << "Pairs for " << n << ":";
    int half = n / 2;
    for(int i = 1; i <= half; ++i) {
        if(i == n - i) break;
        if(i > 1) {
            cout << ",";
        }

        cout << " " << i << " " << n - i;

    }

    cout << "\n";
}

int main() {
    int T, N;
    cin >> T;

    while(T--) {
        cin >> N;
        checkAndPrint(N);

    }

    return 0;

}