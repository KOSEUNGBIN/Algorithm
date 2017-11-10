

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;

int N;
int summary;
vector<pair<int,int>> ELines;
vector<int> memory;

int main()
{
    scanf("%d" , &N);

    ELines.resize(N+1);
    memory.assign(N+1 , 1);
    summary = 0;

    for(int i = 1 ; i <= N ; ++i)
    {
        scanf("%d %d" , &ELines[i].first , &ELines[i].second);
    }

    sort(ELines.begin() + 1 , ELines.end() , less<pair<int,int>>());


    for(int i = 2 ; i <= N ; ++i)
    {
        for(int j = i - 1 ; j > 0 ; --j)
        {
            if((ELines[i].first < ELines[j].first && ELines[i].second < ELines[j].second) || (ELines[i].first > ELines[j].first && ELines[i].second > ELines[j].second))
            {
                memory[i] = max(memory[j] + 1 , memory[i]);
            }
        }
    }

    for(int i = 1 ; i <= N ; ++i)
    {
        summary = max(summary , memory[i]);
    }


    printf("%d\n" , N - summary);

    return 0;
}