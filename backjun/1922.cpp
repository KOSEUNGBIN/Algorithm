//
// Created by 고승빈 on 2017. 10. 11..
//

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int Find(int idx);
int checkCycleAndUnion(int idx1 , int idx2);

struct cmp
{
    bool operator ()(tuple<int , int , int> a , tuple<int , int , int> b)
    {
        return get<2>(a) > get<2>(b);
    }
};

int N , M;
int a , b , c;
int result;
vector<int> vertexList;
priority_queue<tuple<int , int , int> , vector<tuple<int , int , int>> , cmp> pq;

int main()
{
    scanf("%d" , &N);
    scanf("%d" , &M);

    vertexList.assign(N + 1 , 0);

    for(int i = 1 ; i <= N ; ++i)   vertexList[i] = i;

    for(int i = 1 ; i <= M ; ++i)
    {
        scanf("%d %d %d" , &a , &b , &c);

        pq.push(make_tuple(a , b , c));
    }

    result = 0;
    while(!pq.empty())
    {
        if(checkCycleAndUnion(get<0>(pq.top()) , get<1>(pq.top())) > 0) result += get<2>(pq.top());
        pq.pop();
    }

    printf("%d\n", result);

    return 0;
}



int Find(int idx)
{
    if(vertexList[idx] == idx)  return idx;

    return vertexList[idx] = Find(vertexList[idx]);
}

int checkCycleAndUnion(int idx1 , int idx2)
{
    int parent1 , parent2;

    parent1 = Find(idx1);
    parent2 = Find(idx2);

    if(parent1 == parent2)  return -1;

    vertexList[parent1] = parent2;

    return 1;
}