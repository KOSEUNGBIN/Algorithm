//
// Created by 고승빈 on 2017. 10. 11..
//

#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

int N , M;
int A, B;
int cur;
vector<vector<int>> vertexList;
vector<int> degree;
vector<int> result;
priority_queue<int , vector<int> , greater<int>> order;

int main()
{
    scanf("%d %d",&N , &M);

    vertexList.assign(N+1 , vector<int>());
    degree.assign(N+1 , 0);

    for(int i = 1 ; i <= M ; ++i)
    {
        scanf("%d %d" , &A , &B);
        vertexList[A].push_back(B);
        ++degree[B];
    }

    for(int i = 1 ; i <= N ; ++i)
    {
        if(degree[i] == 0) order.push(i);
    }

    while(!order.empty())
    {
        cur = order.top(); order.pop();

        result.push_back(cur);

        for(vector<int>::iterator iter = vertexList[cur].begin(); iter != vertexList[cur].end(); ++iter)
        {
            if(degree[*iter] >= 0)  --degree[*iter];
            if(degree[*iter] == 0) order.push(*iter);
        }
    }

    for(vector<int>::iterator iter = result.begin(); iter != result.end(); ++iter)
    {
        printf("%d " , *iter);
    }
    printf("\n");

    return 0;
}