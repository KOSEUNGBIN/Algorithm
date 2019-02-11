//
// Created by 고승빈 on 2019. 2. 11..
//

#include <iostream>
#include <string>

using namespace std;

int daysOfMonth[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string days[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};


string solution(int a, int b) {
    int date = b;
    for (int month = 1; month < a; ++month) {
        date += daysOfMonth[month];

    }

    int day = (date) % 7;
    return day == 0 ? days[6] : days[day - 1];

}

int main() {
    int a = 5;
    int b = 24;
    cout << solution(a, b) << endl;
    return 0;

}