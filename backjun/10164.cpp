//
// Created by 고승빈 on 2017. 8. 22..
//

#include <iostream>
#include <vector>
using namespace std;

int N , M , K;
int K_X , K_Y;
int cnt , temp;

vector<vector<int>> board;
vector<vector<int>> memory;

int main()
{
    scanf("%d %d %d" , &N , &M , &K);

    board.assign(N + 1 , vector<int>(M + 1));
    memory.assign(N + 1 , vector<int>(M + 1, 0));
    cnt = 0;

    for(int n = 1 ;  n  <= N ; ++n)
    {
        for(int m = 1 ;  m  <= M ; ++m)
        {
            if(++cnt == K)    K_X = m , K_Y = n;
//            board[n][m] = cnt;
//            cnt++;
        }
    }

    memory[1][1] = 1;
    if(K == 0)
    {
        for(int n = 1 ;  n  <= N ; ++n)
        {
            for(int m = 1 ;  m  <= M ; ++m)
            {
                if(n > 1)   memory[n][m] += memory[n-1][m];
                if(m > 1)   memory[n][m] += memory[n][m-1];
            }
        }

    } else{
        for(int n = 1 ;  n  <= K_Y ; ++n)
        {
            for(int m = 1 ;  m  <= K_X ; ++m)
            {
                if(n > 1)   memory[n][m] += memory[n-1][m];
                if(m > 1)   memory[n][m] += memory[n][m-1];
            }
        }

        for(int n = K_Y ;  n  <= N ; ++n)
        {
            for(int m = K_X ;  m  <= M ; ++m)
            {
                if(n == K_Y && m == K_X) continue;

                if(n > 1)   memory[n][m] += memory[n-1][m];
                if(m > 1)   memory[n][m] += memory[n][m-1];
            }
        }
    }

    printf("%d\n",memory[N][M]);

    return 0;
}