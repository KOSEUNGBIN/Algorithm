//
// Created by 고승빈 on 2017. 9. 26..
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>
#include <functional>
#include <algorithm>
using namespace std;

int V , E , K;
int u , v , w;

pair<int , int> cur;

vector<int> vertexInfo;
vector<vector<pair<int , int>>> vertexList;

priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;

int main()
{


    scanf("%d %d" , &V , &E);
    scanf("%d" , &K);

    vertexInfo.assign(V+1 , INT_MAX);
    vertexList.assign(E+1 , vector<pair<int , int>>());

    vertexInfo[K] = 0;

    for(int i = 0 ; i < E ; ++i)
    {
        scanf("%d %d %d" , &u , &v , &w);

        vertexList[u].push_back(make_pair(v , w));
    }

    for(vector<pair<int , int>>::iterator iter = vertexList[K].begin() ; iter != vertexList[K].end(); ++iter)
    {
        pq.push(*iter);
    }


    while(!pq.empty())
    {
        cur = pq.top(); pq.pop();

        if(vertexInfo[cur.first] > cur.second)
        {
            vertexInfo[cur.first] = cur.second;

            for(vector<pair<int , int>>::iterator iter = vertexList[cur.first].begin() ; iter != vertexList[cur.first].end(); ++iter)
            {
                pq.push(make_pair(iter->first , vertexInfo[cur.first] + iter->second));
            }
        }
    }

    for(int i  = 1 ; i < vertexInfo.size() ; ++i)
    {
        if(vertexInfo[i] != INT_MAX)    printf("%d" , vertexInfo[i]);
        else    printf("INF" );

        printf("\n");
    }

    return 0;
}