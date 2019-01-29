//
// Created by 고승빈 on 2019. 1. 29..
//

#define MAX_SERIAL_NUMBER_SIZE 50

#include <iostream>

using namespace std;

int strlen(char str[MAX_SERIAL_NUMBER_SIZE]) {
    int index = 0;
    while (str[index] != '\0') { index++; }
    return index;

}

int sumDigits(char str[MAX_SERIAL_NUMBER_SIZE]) {
    int sum = 0;
    for (int idx = 0, len = strlen(str); idx < len; ++idx) {
        if ('0' <= str[idx] && str[idx] <= '9') {
            sum += (str[idx] - '0');

        }

    }

    return sum;

}

int strcmp(char a[MAX_SERIAL_NUMBER_SIZE], char b[MAX_SERIAL_NUMBER_SIZE]) {
    int aLen = strlen(a);
    int bLen = strlen(b);
    if (aLen != bLen) {
        return (aLen < bLen) ? 1 : -1;

    }

    int aSumDigits = sumDigits(a);
    int bSumDigits = sumDigits(b);
    if (aSumDigits != bSumDigits) {
        return (aSumDigits < bSumDigits) ? 1 : -1;

    }

    for (int idx = 0; idx < aLen; ++idx) {
        if (a[idx] != b[idx]) {
            return (a[idx] < b[idx]) ? 1 : -1;

        }

    }

    return 0;

}

void strcpy(char sour[MAX_SERIAL_NUMBER_SIZE], char dest[MAX_SERIAL_NUMBER_SIZE]) {
    int len = strlen(sour);
    for (int idx = 0; idx < len; ++idx) {
        dest[idx] = sour[idx];

    }

    dest[len] = '\0';

}

void swap(char a[MAX_SERIAL_NUMBER_SIZE], char b[MAX_SERIAL_NUMBER_SIZE]) {
    char temp[MAX_SERIAL_NUMBER_SIZE];
    strcpy(a, temp);
    strcpy(b, a);
    strcpy(temp, b);

}

char **init(int N) {
    char **serialNumbers = new char *[N];
    for (int s = 0; s < N; ++s) {
        serialNumbers[s] = new char[MAX_SERIAL_NUMBER_SIZE];
        cin >> serialNumbers[s];

    }

    return serialNumbers;

}

void sort(int N, char **serialNumbers) {
    for (int idx = 0; idx < N; ++idx) {
        for (int bub = 0; bub < (N - idx - 1); ++bub) {
            if (strcmp(serialNumbers[bub + 1], serialNumbers[bub]) > 0) {
                swap(serialNumbers[bub + 1], serialNumbers[bub]);

            }

        }

    }

}

int main() {
    int N;
    cin >> N;
    char **serialNumbers = init(N);
    sort(N, serialNumbers);
    for (int idx = 0; idx < N; ++idx) {
        cout << serialNumbers[idx] << '\n';

    }

    return 0;

}