//
// Created by 고승빈 on 2017. 9. 26..
//

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
using namespace std;

static const double SPEED = 5;
static const double SECONDS = 2;
static const double CANNONDIST = 50;
static const double MAX = 10000000000;


pair<double , double> cur , dest;

int n;
double compTime;

typedef struct v{
    double time;
    int idx;

    bool operator < (struct v * comp)
    {
        return time < comp->time;
    }
} Vertex;



Vertex * newVertex , * topVertex;

vector<pair<double , double>> coordination;
vector<Vertex> CannonInfo;
vector<vector<double>> CannonsDist;

priority_queue<Vertex *> pq;

int main()
{
    scanf("%lf %lf", &cur.first , &cur.second);
    scanf("%lf %lf", &dest.first , &dest.second);
    scanf("%d" , &n);

    coordination.resize(n+2);
    CannonInfo.resize(n+2);
    CannonsDist.assign(n+2 , vector<double>(n+2));

    coordination[0].first = cur.first , coordination[0].second = cur.second , CannonInfo[0].time = 0 , CannonInfo[0].idx = 0;
    coordination[n+1].first = dest.first , coordination[n+1].second = dest.second , CannonInfo[n+1].time = MAX , CannonInfo[n+1].idx = n+1;


    for(int i = 1 ; i <= n ; ++i)
    {
        scanf("%lf %lf", &coordination[i].first , &coordination[i].second);
        CannonInfo[i].time = MAX , CannonInfo[i].idx = i;
    }

    for(int i = 0 ; i <= n+1 ; ++i)
    {
        for(int j = 0 ; j <= n+1 ; ++j)
        {
            CannonsDist[i][j] = sqrt(pow(coordination[i].first - coordination[j].first , 2) + pow(coordination[i].second - coordination[j].second , 2));
        }
    }

    CannonInfo[n+1].time = CannonsDist[0][n+1] / SPEED;

    for(int i = 1 ; i <= n+1 ; ++i)
    {
        newVertex = new Vertex;
        newVertex->time = CannonsDist[0][i] / SPEED , newVertex->idx = CannonInfo[i].idx;

        pq.push(newVertex);
    }

    while(!pq.empty())
    {
        topVertex = pq.top();   pq.pop();

        if(CannonInfo[topVertex->idx].time > topVertex->time )
        {
            CannonInfo[topVertex->idx].time = topVertex->time;

            for(int i = 1 ; i <= n+1 ; ++i)
            {
                if(topVertex->idx == i) continue;

                compTime = CannonInfo[topVertex->idx].time + min(CannonsDist[topVertex->idx][i] / SPEED , SECONDS + abs(CANNONDIST - CannonsDist[topVertex->idx][i]) / SPEED) ;

                if(CannonInfo[i].time > compTime)
                {

                    newVertex = new Vertex;
                    newVertex->idx = CannonInfo[i].idx;
                    newVertex->time = compTime;

                    pq.push(newVertex);
                }

            }
        }
    }

    printf("%lf\n" , CannonInfo[n+1].time);

    return 0;
}