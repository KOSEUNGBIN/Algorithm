//
// Created by 고승빈 on 2017. 9. 19..
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N , M;
int A , B , C;
int totWeight , maximumWeight;

// compare for sorting
bool comp (tuple<int , int , int> v1 , tuple<int , int , int> v2)
{
    return get<2>(v1) < get<2>(v2);
}

vector<tuple<int , int , int>> edgeList;
vector<int> vertexList;

int Find(int cur);
bool Union(int vertexF , int vertexS);

int main()
{
    scanf("%d %d",&N , &M);

//    input & declare
    edgeList.resize(M+1);   vertexList.resize(N+1);
    maximumWeight = totWeight = 0;

    for(int i = 1 ; i <= N ; ++i)   vertexList[i] = i;
    for(int i = 1 ; i <= M ; ++i)
    {
        scanf("%d %d %d",&A , &B , &C);

        edgeList[i] = make_tuple(A , B , C);
    }

//    sorting
    sort(edgeList.begin() + 1 , edgeList.end(), comp);

//    MST
    for(int i = 1; i <= M; ++i)
    {
        if(Union(get<0>(edgeList[i]) , get<1>(edgeList[i])))
        {
            totWeight += get<2>(edgeList[i]);
            maximumWeight = max(maximumWeight , get<2>(edgeList[i]));
        }
    }

    totWeight -= maximumWeight;

    printf("%d\n", totWeight );

    return 0;
}

// Union & Find
int Find(int cur)
{
    if(vertexList[cur] == cur) return cur;

    return vertexList[cur] = Find(vertexList[cur]);
}

bool Union(int vertexF , int vertexS)
{
    int parentF = Find(vertexF);
    int parentS = Find(vertexS);

    if(parentF == parentS)  return false;

    vertexList[parentF] = parentS;

    return true;
}
