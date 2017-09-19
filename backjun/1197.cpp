//
// Created by 고승빈 on 2017. 9. 19..
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int V , E;
int A , B , C;
int weight;

vector<pair<int,pair<int,int>>> edgeList;
vector<int> vertexList;

pair<int,pair<int,int>> newEdge;

// compare for sort
bool comp(pair<int,pair<int,int>> a , pair<int,pair<int,int>> b)
{
    return a.first < b.first;
}

int Find(int index);
bool Union(int v1 , int v2);

int main()
{
//    input & declare
    scanf("%d %d",&V,&E);

    edgeList.resize(E+1);
    vertexList.resize(V+1);

    for(int i = 1 ; i <= V; ++i)    vertexList[i] = i;

    weight = 0;

    for(int i = 1 ; i <= E ; ++i)
    {
        scanf("%d %d %d" , &A, &B, &C);
        newEdge = make_pair(C , make_pair(A , B));
        edgeList[i] = newEdge;
    }

//    sorting
    sort(edgeList.begin() + 1 , edgeList.end() , comp);

//    MST
    for(vector<pair<int,pair<int,int>>>::iterator iter = edgeList.begin() + 1 ; iter != edgeList.end(); ++iter)
    {
        if(Union(iter->second.first , iter->second.second)) weight += iter->first;
    }


    printf("%d\n",weight);


    return 0;
}

// Union & Find
int Find(int index)
{
    if(vertexList[index] == index)  return index;

    return vertexList[index] = Find(vertexList[index]);
}

bool Union(int v1 , int v2)
{
    int v1_f = Find(v1);
    int v2_f = Find(v2);

    if(v1_f == v2_f)    return false;

    vertexList[v1_f] = v2_f;
    return true;
}