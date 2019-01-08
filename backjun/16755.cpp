//
// Created by 고승빈 on 2019. 1. 8..
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    char text[5] = "HONI";
    string str;
    cin >> str;

    const char *cText = str.c_str();
    int count = 0;
    for (int idx = 0, cur = 0; idx < str.length(); ++idx) {
        if (text[cur] == cText[idx]) {
            if (cur >= 3) {
                cur = 0;
                count++;
            } else {
                cur++;

            }
        }
    }

    cout << count << "\n";

    return 0;

}