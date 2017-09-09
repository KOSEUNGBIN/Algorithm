//
// Created by 고승빈 on 2017. 8. 7..
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

enum Status {NOTYET , VISIT , TRACED};

int N;
vector<int> groups;
vector<Status> visit;
set<int> result;

int dfs(int index)
{
    if(visit[index] == VISIT )    return -1;
    if(visit[index] == TRACED)    return index;

    visit[index] = TRACED;

    int resultUnit = dfs(groups[index]);

    if(resultUnit < 0)
    {
        visit[index] = VISIT;
        return -1;
    }
    else if(resultUnit == 0)
    {
        visit[index] = NOTYET;
        return 0;
    }
    else
    {
        visit[index] = VISIT;
        result.insert(index);
        return resultUnit != index ? resultUnit : 0;
    }


}

int main()
{
    scanf("%d",&N);

    groups.resize(N+1);
    visit.assign(N+1 , NOTYET);

    for(int i = 1 ; i <= N ; ++i)
    {
        scanf("%d", &groups[i]);
    }

    for(int i = 1 ; i <= N; ++i)    dfs(i);

    printf("%d\n",result.size());

    for(set<int>::iterator iter = result.begin(); iter != result.end() ; ++iter)    printf("%d\n",*iter);


    return 0;
}