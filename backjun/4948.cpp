//
// Created by 고승빈 on 2019. 2. 13..
//

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int number) {
    for (int num = 2, last = (int) sqrt(number); num <= last; ++num) {
        if (number % num == 0) {
            return false;

        }

    }

    return true;

}

int main() {
    int n;
    cin >> n;
    do {
        int count = 0;
        for (int num = n + 1, last = 2 * n; num <= last; ++num) {
            if (isPrime(num)) {
                count++;

            }

        }

        cout << count << "\n";
        cin >> n;

    } while (n > 0);

    return 0;

}