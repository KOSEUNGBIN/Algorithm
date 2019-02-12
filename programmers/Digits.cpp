//
// Created by 고승빈 on 2019. 2. 12..
//

#include <iostream>

using namespace std;

char DIGITS[3] = {'1', '2', '4'};

void reverse(string &str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++, right--;

    }

}

string toTrinary(int n) {
    int share = n - 1;
    string result;
    while (share >= 3) {
        result += DIGITS[share % 3];
        share = (share / 3) - 1;

    }

    result += DIGITS[share];
    reverse(result);
    return result;

}

string solution(int n) {
    return toTrinary(n);

}

int main() {
    for (int idx = 1; idx <= 10; idx++) {
        cout << solution(idx) << endl;

    }

    return 0;

}