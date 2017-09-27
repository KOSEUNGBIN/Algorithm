//
// Created by 고승빈 on 2017. 9. 26..
//

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>
#include <limits.h>
using namespace std;


struct cmp{
    bool operator () (tuple<int , int , int> c1 , tuple<int , int , int> c2) {
        return get<2>(c1) < get<2>(c2);
    }
};


int T;
int N , M , K;
int u  , v , c , d;

tuple<int , int , int> cur;

vector<int> vertexInfo;
vector<vector<tuple<int , int , int>>> vertexList;

priority_queue<tuple<int , int , int> , vector<tuple<int , int , int>> , cmp> pq;

int main()
{
    scanf("%d", &T);

    while(T--)
    {
        scanf("%d %d %d" , &N , &M , &K);

        vertexInfo.assign(N+1, INT_MAX);
        vertexList.assign(N+1, vector<tuple<int , int , int>>());

        vertexInfo[1] = 0;

        for(int i = 1 ; i <= K ; ++i)
        {
            scanf("%d %d %d %d" , &u , &v , &c , &d);
            vertexList[u].push_back(make_tuple(v , c , d));
        }

        for(vector<tuple<int , int , int>>::iterator iter = vertexList[1].begin() ; iter != vertexList[1].end() ; ++iter)
        {
            pq.push(*iter);
        }

        while(!pq.empty())
        {
            cur = pq.top(); pq.pop();

            if(vertexInfo[get<0>(cur)] > get<2>(cur) && M >= get<1>(cur))
            {
                vertexInfo[get<0>(cur)] = get<2>(cur);

                for(vector<tuple<int , int , int>>::iterator iter = vertexList[get<0>(cur)].begin() ; iter != vertexList[get<0>(cur)].end() ; ++iter)
                {

                    if(vertexInfo[get<0>(*iter)] > get<2>(*iter) + get<2>(cur) && M >= get<1>(*iter) + get<1>(cur))
                    {
                        pq.push(make_tuple(get<0>(*iter) , get<1>(*iter) + get<1>(cur) , get<2>(*iter) + get<2>(cur)));
                    }
                }
            }

        }

        if(vertexInfo[N] == INT_MAX)
        {
            printf("Poor KCM");
        } else{
            printf("%d", vertexInfo[N]);
        }
        printf("\n");

        vertexInfo.clear();
        vertexList.clear();
    }

    return 0;
}
