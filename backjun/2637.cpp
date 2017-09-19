//
// Created by 고승빈 on 2017. 9. 12..
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>
using namespace std;

int N , M;
int X , Y , K;
int top;

vector<multiset<pair<int,int>>> vertexList;
vector<int> degree;
vector<int> result;
vector<bool> lastCheck;
queue<int> order;

int main()
{
    scanf("%d %d",&N , &M);

//    declare
    vertexList.resize(N+1);
    result.assign(N+1 , 0);
    lastCheck.assign(N+1 , true);
    degree.assign(N+1, 0);

//    input
    for(int m = 1 ; m <= M ; ++m)
    {
        scanf("%d %d %d",&X , &Y, &K);
        vertexList[X].insert(make_pair(Y,K));
        lastCheck[X] = false;

        ++degree[Y];
    }

    order.push(N);

    while(!order.empty())
    {
        top = order.front(); order.pop();

        for(multiset<pair<int,int>>::iterator iter = vertexList[top].begin() ; iter != vertexList[top].end(); ++iter)
        {
            --degree[(*iter).first];

            result[(*iter).first] += (*iter).second * (result[top] = (result[top] > 0 ? result[top] : 1 ));

            if(degree[(*iter).first] == 0)
            {
                order.push((*iter).first);
            }
        }
    }

    for(int i = 1 ; i < result.size(); ++i)
    {
        if(lastCheck[i])    printf("%d %d\n",i,result[i]);
    }


    return 0;
}