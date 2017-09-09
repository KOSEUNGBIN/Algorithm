//
// Created by 고승빈 on 2017. 8. 19..
//

#include <iostream>
#include <cstring>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int T;
int sour , dest ;
bool visit[10000];

queue<pair<int , string>> que;

int D(int value);
int S(int value);
int L(int value);
int R(int value);

pair<int , string> newVertex;

pair<int , string> bfsImp(pair<int , string> vertex)
{

    int d = D(vertex.first);
    int s = S(vertex.first);
    int l = L(vertex.first);
    int r = R(vertex.first);

    pair<int ,string> temp;

    if(!visit[d])
    {
        visit[d] = true;


        temp.first = d;
        temp.second = vertex.second;
        temp.second.append("D");

        if(d == dest)   return temp;
        else
        {
            que.push(temp);
        }
    }

    if(!visit[s])
    {
        visit[s] = true;

        temp.first = s;
        temp.second = vertex.second;
        temp.second.append("S");

        if(s == dest)   return temp;
        else
        {
            que.push(temp);
        }
    }

    if(!visit[l])
    {
        visit[l] = true;

        temp.first = l;
        temp.second = vertex.second;
        temp.second.append("L");

        if(l == dest)   return temp;
        else
        {
            que.push(temp);
        }
    }

    if(!visit[r])
    {
        visit[r] = true;

        temp.first = r;
        temp.second = vertex.second;
        temp.second.append("R");

        if(r == dest)   return temp;
        else
        {
            que.push(temp);
        }
    }

    temp.first = -1;
    return temp;

}

void bfs(pair<int , string> vertex)
{
    if(vertex.first == dest)
        cout << "" << '\n';

    visit[vertex.first] = true;

    pair<int , string> queVertex ,  result;
    que.push(vertex);

    while(!que.empty())
    {
        queVertex = que.front(); que.pop();
        result = bfsImp(queVertex);

        if(result.first >= 0)
        {
            cout << result.second << '\n';
            return ;
        }

    }
}

int main()
{

    scanf("%d" , &T);

    while(T--)
    {
        memset(visit , false , 10000);
        scanf("%d %d" , &sour , &dest);

        newVertex.first = sour;
        newVertex.second = "";

       bfs(newVertex);

        while(!que.empty()) que.pop();


    }

    return 0;
}


int D(int value)
{
    return 2 * value % 10000;
}

int S(int value)
{
    if(value == 0)
    {
        return 9999;
    }
    else
        return value - 1 ;
}

int L(int value)
{
    return (value % 1000) * 10 + value / 1000;
}

int R(int value)
{
    return (value % 10) * 1000 + value / 10 ;
}