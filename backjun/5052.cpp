//
// Created by 고승빈 on 2018. 10. 5..
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool checkConsistency(vector<vector<string>>* phoneNumbers, const string &str) {
    int idx = str.size();
    for(int i = 1; i < idx; ++i) {
        string subStr = str.substr(0, i);
        for (const string idxStr : (*phoneNumbers)[i]) {
            int result = subStr.compare(idxStr);
            if(result == 0) {
                return false;

            } else if(result < 0) {
                break;

            }

        }

    }

    return true;

}

int main() {
    std::ios::sync_with_stdio(false);
    int T;

    cin >> T;
    while(T--) {
        int N;
        string input;
        vector<vector<string>> phoneNumbers(11);

        cin >> N;
        for(int n = 1; n <= N; ++n) {
            cin >> input;
            phoneNumbers[input.size()].push_back(input);

        }

        for(int n = 1; n <= 10; ++n) {
            sort(phoneNumbers[n].begin(), phoneNumbers[n].end());

        }

        bool isConsistency = true;
        for(int n = 10; n > 0; --n) {
            for (string str : phoneNumbers[n]) {
                if (!checkConsistency(&phoneNumbers, str)) {
                    isConsistency = false;  break;

                }

            }

        }

        cout << (isConsistency ? "YES" : "NO") << '\n';

    }

    return 0;

}