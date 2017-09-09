//
// Created by 고승빈 on 2017. 7. 29..
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct edge{

    int sour , dest , dist;

} Edge;

typedef struct vertex{

    int x , y , z;
    int num;

} Vertex;

class comp{
public:
    bool operator()(Edge * a , Edge * b)
    {
        return a->dist > b->dist;
    }
};

bool compareX(Vertex a , Vertex b)
{
    return a.x < b.x;
}

bool compareY(Vertex a , Vertex b)
{
    return a.y < b.y;
}

bool compareZ(Vertex a , Vertex b)
{
    return a.z < b.z;
}

int N;
int minimum , result , vertexCnt;

Edge * newEdge  , * sNewEdge , * topEdge , *topTemp;

vector<Vertex> vertexList;

vector<bool> visit;
vector<int> arr;
vector<int> height;


priority_queue<Edge * , vector<Edge * > ,comp> pq;

int Find(int a)
{
    if(arr[a] != a) return arr[a] = Find(arr[a]);

    return a;
}

void Union(int a , int b)
{
    int rootA = Find(a);
    int rootB = Find(b);

    if(rootA == rootB)  return;

    if(height[rootA] > height[rootB])
    {
        arr[rootA] = rootB;
        height[rootB] = height[rootA] + 1;
    } else{
        arr[rootB] = rootA;
        height[rootA] = height[rootB] + 1;
    }


}

int main()
{
    scanf("%d",&N);

    vertexList.resize(N+1);
    visit.assign(N+1 , false);
    arr.resize(N+1);
    height.assign(N+1,0);



    for(int i = 1 ; i <= N ; ++i)
    {
        vertexList[i].num = i;
        scanf("%d %d %d", &vertexList[i].x ,&vertexList[i].y,&vertexList[i].z);
        arr[i] = i;
    }


    sort(vertexList.begin() + 1 , vertexList.end() , compareX);

    for(int i = 2 ; i <= N ; ++i)
    {
        newEdge = new Edge;
        sNewEdge = new Edge;

        newEdge->dist = min(abs(vertexList[i].x - vertexList[i-1].x) , min(abs(vertexList[i].y - vertexList[i-1].y) , abs(vertexList[i].z - vertexList[i-1].z)));    newEdge->sour = vertexList[i-1].num;  newEdge->dest = vertexList[i].num;
        sNewEdge->dist = newEdge->dist; sNewEdge->sour = newEdge->dest; sNewEdge->dest = newEdge->sour;


        pq.push(newEdge);

        pq.push(sNewEdge);


    }

    sort(vertexList.begin() + 1 , vertexList.end() , compareY);

    for(int i = 2 ; i <= N ; ++i)
    {
        newEdge = new Edge;
        sNewEdge = new Edge;

        newEdge->dist = min(abs(vertexList[i].x - vertexList[i-1].x) , min(abs(vertexList[i].y - vertexList[i-1].y) , abs(vertexList[i].z - vertexList[i-1].z)));    newEdge->sour = vertexList[i-1].num;  newEdge->dest = vertexList[i].num;
        sNewEdge->dist = newEdge->dist; sNewEdge->sour = newEdge->dest; sNewEdge->dest = newEdge->sour;


        pq.push(newEdge);
        pq.push(sNewEdge);
    }

    sort(vertexList.begin() + 1 , vertexList.end() , compareZ);

    for(int i = 2 ; i <= N ; ++i)
    {
        newEdge = new Edge;
        sNewEdge = new Edge;

        newEdge->dist = min(abs(vertexList[i].x - vertexList[i-1].x) , min(abs(vertexList[i].y - vertexList[i-1].y) , abs(vertexList[i].z - vertexList[i-1].z)));    newEdge->sour = vertexList[i-1].num;  newEdge->dest = vertexList[i].num;
        sNewEdge->dist = newEdge->dist; sNewEdge->sour = newEdge->dest; sNewEdge->dest = newEdge->sour;


        pq.push(newEdge);
        pq.push(sNewEdge);
    }

    result = 0;

    while(!pq.empty())
    {
        topEdge = pq.top(); pq.pop();

        if(Find(topEdge->sour) != Find(topEdge->dest))
        {
            Union(topEdge->sour , topEdge->dest);
            result += topEdge->dist;
        }


    }



    printf("%d\n",result);
}