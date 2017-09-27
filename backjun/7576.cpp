//
// Created by 고승빈 on 2017. 9. 27..
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int M , N;
int minDay;
bool allNot , all;
pair<int ,pair<int , int>> topCo;
vector<vector<int>> board , check;
vector<vector<bool>> visit;

queue<pair<int ,pair<int , int>>> order;

void bfs(pair<int, int> coordi , int day);

int main()
{
    scanf("%d %d" , &M , &N);

    board.assign(N+1 , vector<int>(M+1));
    check.assign(N+1 , vector<int>(M+1));

    minDay = 1; allNot = false; all = true;

    visit.assign(N+1 , vector<bool>(M+1 , false));

    for(int i = 1 ; i <= N; ++i)
    {
        for(int j = 1 ; j <= M; ++j)
        {
            scanf("%d" , &board[i][j]);

            check[i][j] = board[i][j];

            if(board[i][j] != 0) all = false;
            if(board[i][j] == 1)
            {
                visit[i][j] = true;
                order.push(make_pair( check[i][j] , make_pair(i , j)));
            }
        }
    }

    while(!order.empty())
    {
        topCo = order.front(); order.pop();
        bfs(topCo.second , topCo.first);
    }
    visit.clear();

    for(int i = 1 ; i <= N; ++i)
    {
        for(int j = 1 ; j <= M; ++j)
        {
            if(board[i][j] == -1) continue;
            else if(board[i][j] == 0)
            {
                allNot = true;
            } else{
                minDay = max(minDay , board[i][j]);
            }
        }
    }

    if(allNot)                  printf("-1\n");
    else if(all)               printf("0\n");
    else                        printf("%d\n" , minDay - 1);

    return 0;
}

void bfs(pair<int, int> coordi , int day)
{
    if( !(1 > coordi.first - 1 || coordi.first - 1 > N || 1 > coordi.second || coordi.second > M))
    {
        if(!visit[coordi.first - 1][coordi.second] && board[coordi.first - 1][coordi.second] == 0)
        {
            board[coordi.first - 1][coordi.second] = day + 1;
            order.push(make_pair(day + 1 ,make_pair(coordi.first - 1 , coordi.second)));
            visit[coordi.first - 1][coordi.second]  = true;
        }

        if(!visit[coordi.first - 1][coordi.second] && board[coordi.first - 1][coordi.second] >= 1)
        {
            board[coordi.first - 1][coordi.second] = min(board[coordi.first - 1][coordi.second] , day + 1);
            order.push(make_pair(day + 1 ,make_pair(coordi.first - 1 , coordi.second)));
            visit[coordi.first - 1][coordi.second]  = true;
        }


    }

    if( !(1 > coordi.first + 1 || coordi.first + 1 > N || 1 > coordi.second || coordi.second > M))
    {
        if(!visit[coordi.first + 1][coordi.second] && board[coordi.first + 1][coordi.second] == 0) {
            board[coordi.first + 1][coordi.second] = day + 1;
            order.push(make_pair(day + 1, make_pair(coordi.first + 1, coordi.second)));
            visit[coordi.first + 1][coordi.second]  = true;
        }

        if(!visit[coordi.first + 1][coordi.second] && board[coordi.first + 1][coordi.second] >= 1)
        {
            board[coordi.first + 1][coordi.second] = min(board[coordi.first + 1][coordi.second] , day + 1);
            order.push(make_pair(day + 1, make_pair(coordi.first + 1, coordi.second)));
            visit[coordi.first + 1][coordi.second]  = true;
        }
    }

    if(!(1 > coordi.first || coordi.first > N || 1 > coordi.second - 1 || coordi.second - 1 > M))
    {
        if(!visit[coordi.first ][coordi.second - 1] && board[coordi.first ][coordi.second - 1] == 0) {
            board[coordi.first][coordi.second - 1] = day + 1;
            order.push(make_pair(day + 1, make_pair(coordi.first , coordi.second - 1)));
            visit[coordi.first ][coordi.second - 1]  = true;
        }

        if(!visit[coordi.first ][coordi.second - 1] && board[coordi.first][coordi.second - 1] >= 1)
        {
            board[coordi.first][coordi.second - 1] = min(board[coordi.first][coordi.second - 1] , day + 1);
            order.push(make_pair(day + 1, make_pair(coordi.first , coordi.second - 1)));
            visit[coordi.first ][coordi.second - 1]  = true;
        }
    }

    if(!(1 > coordi.first || coordi.first > N || 1 > coordi.second + 1 || coordi.second + 1 > M))
    {
        if(!visit[coordi.first ][coordi.second + 1] && board[coordi.first ][coordi.second + 1] == 0) {
            board[coordi.first][coordi.second + 1] = day + 1;
            order.push(make_pair(day + 1, make_pair(coordi.first , coordi.second + 1)));
            visit[coordi.first][coordi.second + 1]  = true;
        }

        if(!visit[coordi.first ][coordi.second + 1] && board[coordi.first][coordi.second + 1] >= 1)
        {
            board[coordi.first][coordi.second + 1] = min(board[coordi.first][coordi.second + 1] , day + 1);
            order.push(make_pair(day + 1, make_pair(coordi.first , coordi.second + 1)));
            visit[coordi.first][coordi.second + 1]  = true;
        }
    }

}