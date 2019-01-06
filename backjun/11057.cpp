//
// Created by 고승빈 on 2019. 1. 6..
//

#include <iostream>
#include <string>
#include <string.h>

#define MAX_SIZE 1001
#define DIGIT_SIZE 10
#define REST 10007

using namespace std;

int search(int cache[][DIGIT_SIZE], int N, int curN, int value) {
    if (curN > N) {
        return 0;

    } else if (curN == N) {
        return 1;

    } else {
        if (cache[curN][value] >= 0) {
            return cache[curN][value];

        }

        int result = 0;
        for (int num = 0; num < DIGIT_SIZE; ++num) {
            if (value <= num) {
                result += (search(cache, N, curN + 1, num) % REST);

            }

        }

        return cache[curN][value] = result;

    }

}

void init(int cache[][DIGIT_SIZE]) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        memset(cache[i], -1, sizeof(int) * DIGIT_SIZE);

    }

}

int main() {
    int N;
    cin >> N;

    int cache[MAX_SIZE][DIGIT_SIZE];
    init(cache);

    int count = 0;
    for (int num = 0; num < DIGIT_SIZE; ++num) {
        count += search(cache, N, 1, num);

    }

    cout << count % REST << "\n";
    return 0;

}