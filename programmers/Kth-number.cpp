//
// Created by 고승빈 on 2019. 1. 5..
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> subArray(vector<int> array, int start, int end) {
    vector<int> sub;
    for (int idx = start; idx <= end; ++idx) {
        sub.push_back(array[idx]);

    }

    return sub;

}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;

}

void quickSort(vector<int> &array, int left, int right) {
    int l = left;
    int r = right;
    int pivot = array[(left + right) / 2];
    while (l <= r) {
        while (array[l] < pivot) { ++l; }
        while (array[r] > pivot) { --r; }

        if (l <= r) {
            swap(array[l], array[r]);
            ++l, --r;

        }

    }

    if (left < l) {
        quickSort(array, left, r);

    }

    if (r < right) {
        quickSort(array, l, right);

    }

}


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> command : commands) {
        vector<int> sub = subArray(array, command[0] - 1, command[1] - 1);
        quickSort(sub, 0, sub.size() - 1);
        answer.push_back(sub[command[2] - 1]);

    }

    return answer;

}

int main() {
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3},
                                    {4, 4, 1},
                                    {1, 7, 3}};
    vector<int> result = solution(array, commands);
    for (int r : result) {
        cout << r << " ";

    }

    cout << endl;
    return 0;

}