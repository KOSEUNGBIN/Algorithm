//
// Created by 고승빈 on 2018. 10. 23..
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> checker;
    sort(phone_book.begin(), phone_book.end());
    for(string list : phone_book) {
        for(int idx = 0; idx < list.size(); ++idx) {
            string subStr = list.substr(0, idx);
            if (checker.find(subStr) != checker.end()) {
                return false;

            }

            checker.insert(list);

        }

    }

    return answer;

}
