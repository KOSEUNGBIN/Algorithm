//
// Created by 고승빈 on 2017. 9. 29..
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T , N;
int searchResult;
char input;

typedef struct v{
    bool isBob;
    int memory;
} Vertex;

Vertex * curVertex;

vector<vector<Vertex>> board;
vector<int> result;
priority_queue<Vertex *> pq;

void bfs(Vertex * cur , bool isDown);

int main()
{
    scanf("%d" , &T);

    while(T--)
    {
        scanf("%d", &N);
        board.assign(N+1 , vector<Vertex>(N+1));

        for(int i = 1 ; i <= N ; ++i)
        {
            for(int j = 1 ; j <= N ; ++j)
            {
                scanf("%c" , &input);
                board[i][j].isBob = (input == 'B');
                board[i][j].memory = 0;
            }
        }

        while(!pq.empty())
        {
            curVertex = pq.top(); pq.pop();

            bfs(curVertex)
        }

        result.push_back(searchResult);
    }

    return 0;
}

void bfs(Vertex * cur , bool isDown)
{

}