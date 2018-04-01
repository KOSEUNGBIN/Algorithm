//
// Created by 고승빈 on 2018. 4. 1..
//

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<string> &words, int start, int end, int mid) {
    vector<string> tmp;
    int i = start, j = mid + 1;
    int cmp;
    size_t fLen, sLen;
    while (i <= mid && j <= end) {
        fLen = words[i].length();
        sLen = words[j].length();
        if (fLen > sLen) {
            tmp.push_back(words[j++]);
        } else if (fLen < sLen) {
            tmp.push_back(words[i++]);
        } else {
            cmp = words[i].compare(words[j]);
            if (cmp > 0) {
                tmp.push_back(words[j++]);
            } else {
                tmp.push_back(words[i++]);
            }
        }
    }

    while (i <= mid) {
        tmp.push_back(words[i++]);
    }
    while (j <= end) {
        tmp.push_back(words[j++]);
    }

    for (int k = 0; k < tmp.size(); ++k) {
        words[start + k] = tmp[k];
    }
}

void mergeSort(vector<string> &words, int start, int end) {
    if (start < end) {
        int mid = ((end + start) / 2);
        mergeSort(words, start, mid);
        mergeSort(words, mid + 1, end);
        merge(words, start, end, mid);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int N;
    vector<string> words;
    string input;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> input;
        words.push_back(input);
    }

    mergeSort(words, 0, N - 1);
    int before = 0;
    cout << words[before] << "\n";
    for (int i = 1; i < words.size(); before = i, ++i) {
        if (words[before].compare(words[i]) != 0) {
            cout << words[i] << "\n";
        }
    }

    return 0;
}