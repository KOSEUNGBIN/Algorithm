//
// Created by 고승빈 on 2017. 8. 12..
//

#include <iostream>
#include <algorithm>
using namespace std;

int T ,N;
int sticker[3][1000001];
int result[3][1000001];

int main()
{

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&N);


        for(int i = 1 ; i <= 2 ; ++i)
        {
            for(int j = 1; j<= N ; ++j) scanf("%d",&sticker[i][j]);
        }

        result[1][1] = sticker[1][1];
        result[2][1] = sticker[2][1];

        result[1][2] = sticker[1][2] + sticker[2][1];
        result[2][2] = sticker[2][2] + sticker[1][1];

        for(int i = 3 ; i <= N ; ++i)
        {
            result[1][i] = max(max(result[1][i-2],result[2][i-2]) , result[2][i-1]) + sticker[1][i];
            result[2][i] = max(max(result[2][i-2],result[1][i-2]) , result[1][i-1]) + sticker[2][i];

        }
        printf("%d\n", max(result[1][N], result[2][N]));
    }

    return 0;
}
