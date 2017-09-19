//
// Created by 고승빈 on 2017. 9. 12..
//

#include <iostream>
#include <vector>
#include <queue>
#define END -1000
using namespace std;


int N , M;
int num;
int sour , dest;
int top;

bool check;

vector<vector<int>> vertexList;
vector<int> degree;
vector<int> result;
queue<int> order;

int main()
{

    scanf("%d %d",&N,&M);
    vertexList.resize(N+1);
    degree.assign(N+1 , 0);

//  input
    for(int n = 1 ; n <= M; ++n)
    {
        scanf("%d", &num);
        scanf("%d",&sour);
        for(int s = 1 ; s < num ; ++s)
        {
            scanf("%d", &dest);
            vertexList[sour].push_back(dest);
            ++degree[dest];
            sour = dest;

        }
    }

//    check init value
    check = false;
    for(int i = 1 ; i < degree.size(); ++i)
    {
        if(degree[i] == 0)
        {
            order.push(i);
            check = true;
        }
    }


//    Topological Sort
    while(!order.empty())
    {
        top = order.front(); order.pop();
        result.push_back(top);
        degree[top] = END;

        for(vector<int>::iterator iter = vertexList[top].begin(); iter != vertexList[top].end(); ++iter)
        {
            --degree[*iter];
            if(degree[*iter] != END && degree[*iter] <= 0)
            {
                order.push(*iter);
            }
        }


    }

//   check DAG
    for(int i = 1 ; i < degree.size(); ++i)
    {
        if(degree[i] > 0)
        {
            check = false;
            break;
        }
    }

//    result
    if(!check)
    {
        printf("0\n");  return 0;
    }


    for(vector<int>::iterator iters = result.begin(); iters != result.end(); ++iters)
    {
        printf("%d\n",*iters);
    }


    return 0;
}