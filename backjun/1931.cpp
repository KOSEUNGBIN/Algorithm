//
// Created by 고승빈 on 2017. 8. 12..
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> a , pair<int,int> b)
{
    if(a.second < b.second) return true;
    else if(a.second == b.second && a.first < b.first) return true;
    else return false;
}

int main()
{
    int N , result = 1;
    int endTime;

    scanf("%d",&N);

    vector<pair<int , int>> room(N);

    for(int i = 0 ; i < N ; ++i)
    {
        scanf("%d %d" , &room[i].first , &room[i].second);
    }

    sort(room.begin() , room.end() , comp);

    vector<pair<int , int>>::iterator iter = room.begin();
    endTime = iter->second;

    while(++iter != room.end())
    {
        if(iter->first < endTime)
        {
            continue;
        }
        else{
            ++result;
            endTime = iter->second;
        }
    }

    printf("%d\n",result);

    return 0;
}

