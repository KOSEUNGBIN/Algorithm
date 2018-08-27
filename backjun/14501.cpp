//
// Created by 고승빈 on 2018. 9. 7..
//

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N;
pair<int, int> consultResources[16];

int printBenefit();
int getMaxBenefit(int curDay);

int main() {


    scanf("%d", &N);
    for(int idx = 1; idx <= N; ++idx) {
        scanf("%d %d", &consultResources[idx].first, &consultResources[idx].second);

    }

    printf("%d\n", printBenefit());
    return 0;

}

int printBenefit() {
    int maxBenefit = 0;
    for(int startDay = 1; startDay <= N; ++startDay) {
        maxBenefit = max(maxBenefit, getMaxBenefit(startDay));

    }

    return maxBenefit;

}

int getMaxBenefit(int curDay) {
    int maxBenefit = 0;
    for(int day = curDay; day <= N; ++day) {
        int nextDay = day + consultResources[day].first;
        if(nextDay <= (N + 1)) {
            maxBenefit = max(maxBenefit, consultResources[day].second + getMaxBenefit(nextDay));

        }

    }

    return maxBenefit;

}