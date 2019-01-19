//
// Created by 고승빈 on 2019. 1. 20..
//

#include <string>
#include <vector>

#define MAX_SIZE 3
#define MAX_FIRST_SIZE 5
#define MAX_SECOND_SIZE 8
#define MAX_THIRD_SIZE 10

using namespace std;


int correctCount(vector<int> answers, int values[], int N) {
    int idx = 0;
    int count = 0;
    for (int v : answers) {
        if (values[(idx % N)] == v) {
            count++;
        }

        ++idx;

    }

    return count;

}


vector<int> solution(vector<int> answers) {
    int values[MAX_SIZE][MAX_THIRD_SIZE] =
            {{1, 2, 3, 4, 5},
             {2, 1, 2, 3, 2, 4, 2, 5},
             {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};

    int size[MAX_SIZE] = {MAX_FIRST_SIZE, MAX_SECOND_SIZE, MAX_THIRD_SIZE};
    int max = 0;
    int counts[MAX_SIZE];
    for (int idx = 0; idx < MAX_SIZE; ++idx) {
        counts[idx] = correctCount(answers, values[idx], size[idx]);
        if (max < counts[idx]) {
            max = counts[idx];

        }

    }

    vector<int> result;
    for (int idx = 0; idx < MAX_SIZE; ++idx) {
        if (counts[idx] == max) {
            result.push_back(idx + 1);

        }

    }

    return result;

}