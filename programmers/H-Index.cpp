//
// Created by 고승빈 on 2019. 1. 1..
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;

}

void quickSort(vector<int> &arr, int left, int right) {
    int l = left, r = right;
    int pivot = arr[(left + right) / 2];
    while (l <= r) {
        while (arr[l] < pivot) { ++l; }
        while (arr[r] > pivot) { --r; }
        if (l <= r) {
            swap(arr[l], arr[r]);
            l++, r--;

        }

    }

    if (left < l) {
        quickSort(arr, left, r);

    }

    if (r < right) {
        quickSort(arr, l, right);

    }

}

bool checkQuotedCount(vector<int> &citations, int &cur, int index) {
    while (citations[cur] < index) { cur++; }
    return (citations.size() - cur) >= index;

}

int searchHIndex(vector<int> &citations) {
    int result = 0;
    int index = 0, cur = 0;
    while (index <= citations.size()) {
        if (checkQuotedCount(citations, cur, index)) {
            result = index;

        }

        ++index;

    }

    return result;

}

int solution(vector<int> citations) {
    quickSort(citations, 0, citations.size() - 1);
    return searchHIndex(citations);

}


int main() {
    vector<int> arr
            = {3, 0, 6, 1, 5};
//            = {22, 42};
    cout << solution(arr) << endl;
    return 0;

}
