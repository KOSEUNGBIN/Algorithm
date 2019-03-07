//
// Created by 고승빈 on 2019-03-07.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int bitCount(int number) {
    int num = number;
    int count = 0;
    while(num > 0) {
        if(num % 2 == 1) {
            count++;

        }

        num /= 2;

    }

    return count;

}

int solution(int n) {
    int answer = n;
    int beginBitCount = bitCount(n);
    while(beginBitCount != bitCount(++answer)) { }
    return answer;

}

int main() {
    cout << solution(78) << endl;
    return 0;

}