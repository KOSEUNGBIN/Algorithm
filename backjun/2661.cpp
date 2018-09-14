//
// Created by 고승빈 on 2018. 9. 14..
//
#include <iostream>
using namespace std;

char* searchMin(int N, int curN, int digit[]);

int main() {
    int N;
    int digit[81];

    cin >> N;
    cout << searchMin(N, 1, digit) << "\n";

    return 0;

}

bool checkSymmetry(int N, int digit[], int start, int count) {
    int next = start + count;
    if(next + count > N) return false;

    for(int idx = start; idx < next; ++idx) {
        if(digit[idx] != digit[idx + count]) {
            return false;

        }

    }

    return true;

}

bool checkRight(int N, int digit[]) {
    for(int cnt = 1; cnt <= N / 2; ++cnt) {
        for (int n = 1; n <= N; ++n) {
            if (checkSymmetry(N, digit, n, cnt)) {
                return false;

            }

        }

    }

    return true;

}

char* transDigit(int N, int digit[]) {
    char digits[3] = {'1', '2', '3'};
    char* str = new char[N + 1];

    for(int n = 0; n < N; ++n) {
        str[n] = digits[digit[n + 1] - 1];

    }

    str[N] = '\0';
    return str;

}

char* searchMin(int N, int curN, int digit[]) {
    if(!checkRight(curN, digit)) {
        return NULL;

    }

    if(curN > N) {
        return transDigit(N, digit);

    }

    for(int v = 1; v <= 3; ++v) {
        digit[curN] = v;
        char* result = searchMin(N, curN + 1, digit);

        if(result != NULL) {
            return result;

        }

    }

    return NULL;

}