//
// Created by 고승빈 on 2019. 2. 13..
//

#include <iostream>
using namespace std;

int main() {
    int day;
    cin >> day;

    int count = 0;
    for(int in = 0; in < 5; in++) {
        int input;
        cin >> input;
        if(day == input) {
            count++;

        }

    }

    cout << count << endl;
    return 0;

}