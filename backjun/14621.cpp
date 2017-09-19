//
// Created by 고승빈 on 2017. 9. 19..
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N , M;
int u , v , d;
int totWeight;
string inputG;


typedef struct e{
    int vertex_f, vertex_s;
    int weight;
    int index;
    bool visit;

    bool operator < (const struct e & edge) const
    {
        return weight > edge.weight;
    }

} Edge;

typedef struct v{
    bool gender;
    bool visit;
    vector<Edge * > edgeList;
} Vertex;

vector<Vertex> vertexList;
vector<Edge> edgeList;

Edge * minEdge , curEdge;

priority_queue<Edge> pq;

int main()
{
    ios::sync_with_stdio(false);

    cin >> N >> M;  totWeight = 0;

    vertexList.resize(N+1); edgeList.resize(M+1);

//    input & declare
    for(int i = 1 ; i <= N ; ++i)
    {
        cin >> inputG;
        vertexList[i].visit = false;
        vertexList[i].gender = (inputG == "M");
    }

    for(int i = 1; i <= M ; ++i)
    {
        cin >> u >> v >> d;

        edgeList[i].vertex_f = u; edgeList[i].vertex_s = v; edgeList[i].weight = d; edgeList[i].visit = false;  edgeList[i].index = i;
        vertexList[u].edgeList.push_back(&edgeList[i]);
        vertexList[v].edgeList.push_back(&edgeList[i]);

        if(vertexList[edgeList[i].vertex_f].gender ^ vertexList[edgeList[i].vertex_s].gender)
        {
            if(minEdge == NULL || minEdge->weight > edgeList[i].weight) minEdge = &edgeList[i];
        }
    }

//    MST
    if(minEdge != NULL)
    {
        pq.push(*minEdge);


        while(!pq.empty())
        {

            curEdge = pq.top(); pq.pop();

            if(curEdge.visit) continue;
            edgeList[curEdge.index].visit = true;

            if((!vertexList[curEdge.vertex_f].visit || !vertexList[curEdge.vertex_s].visit) && (vertexList[curEdge.vertex_f].gender ^ vertexList[curEdge.vertex_s].gender))
            {
                totWeight += curEdge.weight;
            }
            else    continue;


            if(!vertexList[curEdge.vertex_f].visit)
            {
                vertexList[curEdge.vertex_f].visit = true;
                for(vector<Edge * >::iterator iter = vertexList[curEdge.vertex_f].edgeList.begin(); iter != vertexList[curEdge.vertex_f].edgeList.end(); ++iter)
                {
                    pq.push((**iter));
                }
            }

            if(!vertexList[curEdge.vertex_s].visit)
            {
                vertexList[curEdge.vertex_s].visit = true;
                for(vector<Edge * >::iterator iter = vertexList[curEdge.vertex_s].edgeList.begin(); iter != vertexList[curEdge.vertex_s].edgeList.end(); ++iter)
                {
                    pq.push((**iter));
                }
            }

        }

        for(int i = 1 ; i <= N ; ++i)
        {
            if(!vertexList[i].visit)
            {
                printf("-1\n"); return 0;
            }
        }

        printf("%d\n",totWeight);

    } else{
        printf("-1\n"); return 0;
    }

    return 0;
}