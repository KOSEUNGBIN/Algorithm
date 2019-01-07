//
// Created by 고승빈 on 2019. 1. 7..
//

#include <string>
#include <vector>
#include <iostream>

#define MAX_BUDGET 100001
#define MIN_BUDGET 0
#define BAD_CASE 0

using namespace std;

int calUpperLimit(vector<int> &budgets, int limit) {
    int budget = 0;
    for (int idx : budgets) {
        budget += (idx <= limit ? idx : limit);

    }

    return budget;

}


int search(int left, int right, int min, int max, int M, vector<int> &budgets) {
    if (left < min || max < right) {
        return BAD_CASE;

    }

    if (left <= right) {
        int middle = (left + right) / 2;
        int middleUpperLimit = calUpperLimit(budgets, middle);
        if (middleUpperLimit <= M) {
            int rightCase = search(middle + 1, right, min, max, M, budgets);
            return middle >= rightCase ? middle : rightCase;

        } else {
            return search(left, middle - 1, min, max, M, budgets);

        }

    }

    return BAD_CASE;

}


int maxBudget(vector<int> budgets) {
    int result = MIN_BUDGET;
    for (int v : budgets) {
        if (result < v) {
            result = v;

        }

    }

    return result;

}


int minBudget(vector<int> budgets) {
    int result = MAX_BUDGET;
    for (int v : budgets) {
        if (result > v) {
            result = v;

        }

    }

    return result;

}


int solution(vector<int> budgets, int M) {
    int min = minBudget(budgets);
    int max = maxBudget(budgets);
    int result = search(min, max, min, max, M, budgets);
    return result == 0 ? (int) (M / budgets.size()) : result;

}


int main() {
    vector<int> arr = {120, 110, 140, 150};
    cout << solution(arr, 485) << endl;
    return 0;

}