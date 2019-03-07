//
// Created by 고승빈 on 2019-03-07.
//

#include <iostream>
#include <vector>

#define OPERATION_SIZE 5
#define MAX_COUNT 8

using namespace std;

int calculate(int a, int b, int op) {
    if (op == 1) {
        return a + b;

    } else if (op == 2) {
        return a - b;

    } else if (op == 3) {
        return a * b;

    } else if (op == 4) {
        return a / b;

    }

    return -1;

}

int calculate(int number, vector<int> &operations) {
    int result = 0;
    int nextNumber = number;
    for (int op : operations) {
        if (op == 0) {
            nextNumber *= 10;
            nextNumber += number;

        } else {
            result = calculate(result, nextNumber, op);
            nextNumber = number;

        }

    }

    return result;

}

bool search(vector<int> &operations, int number, int targetNumber, int count, int maxCount) {
    if (count >= maxCount) { return targetNumber == calculate(number, operations); }
    for (int op = 0; op < OPERATION_SIZE; ++op) {
        operations.push_back(op);
        if (search(operations, number, targetNumber, count + 1, maxCount)) {
            return true;

        }

        operations.pop_back();

    }

    return false;

}

int solution(int N, int number) {
    vector<int> operations;
    for (int count = 0; count <= MAX_COUNT; ++count) {
        if (search(operations, N, number, 0, count)) {
            return count;

        }

    }

    return -1;

}

int main() {
    cout << solution(2, 11) << endl;
    return 0;

}