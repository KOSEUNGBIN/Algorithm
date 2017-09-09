//
// Created by 고승빈 on 2017. 8. 22..
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef struct e{
    int dest;
    int second;
} Edge;

typedef struct v{
    vector<Edge * > edgeList;
} Vertex;

class comp{
public:
    bool operator() (pair<int, int> a , pair<int, int> b)
    {
        return a.second > b.second;
    }
};

const static int BIG = 100000032032;

int T;
int n , d , c;
int a , b , s;

int tot , tot_sec;
Edge * newEdge;

vector<Vertex> vertexList;
vector<int> dist;

priority_queue<pair<int, int> , vector<pair<int, int>> ,comp>  pq;

void search();

int main()
{
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d %d",&n , &d , &c);


        tot = tot_sec = 0;

        vertexList.clear();
        dist.clear();

        vertexList.resize(n+1);
        dist.assign(n+1 , BIG);

        for(int i = 1 ; i <= n ; ++i)   pq.push(make_pair(i , (i != c ? BIG : 0)));
        dist[c] = 0;

        for(int i = 1 ; i <= d ; ++i)
        {
            newEdge = new Edge;

            scanf("%d %d %d",&b , &a , &s);

            newEdge->dest = b;
            newEdge->second = s;

            vertexList[a].edgeList.push_back(newEdge);

        }


        search();

        printf("%d %d\n", tot_sec , tot);

    }



    return 0;
}

void search()
{

    pair<int, int> cur;

    while(!pq.empty())
    {
        cur = pq.top(); pq.pop();

        for(vector<Edge * >::iterator iter = vertexList[cur.first].edgeList.begin() ; iter != vertexList[cur.first].edgeList.end() ; ++iter)
        {
            if(dist[(*iter)->dest] > cur.second +  (*iter)->second)
            {
                dist[(*iter)->dest] = cur.second +  (*iter)->second;
                pq.push(make_pair((*iter)->dest , dist[(*iter)->dest]));

            }
        }
    }

    for(int i = 1 ; i <= n ; ++i)
    {
        if(dist[i] < BIG)
        {
            tot = max( tot , dist[i]);
            ++tot_sec;
        }
    }

}
