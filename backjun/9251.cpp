//
// Created by 고승빈 on 2017. 10. 9..
//

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

char inputF[1001];
char inputS[1001];
int memory[1002][1002] = {0,};
int F_len , S_len;

int main()
{
    fgets(inputF , 1001 , stdin);
    fgets(inputS , 1001 , stdin);

    F_len = strlen(inputF) - 1;
    S_len = strlen(inputS) - 1;

    if(F_len >= S_len)
    {
        for(int i  = 1 ; i <= S_len ; ++i)
        {
            for(int j = 1 ; j <= F_len; ++j)
            {
                if(inputS[i - 1] == inputF[j - 1])
                {
                    memory[i][j] = memory[i-1][j-1] + 1;

                } else{
                    memory[i][j] = max(memory[i][j-1] , memory[i][j] = memory[i-1][j]);
                }
            }
        }

        printf("%d\n" , memory[S_len][F_len]);

    } else{
        for(int i  = 1 ; i <= F_len ; ++i)
        {
            for(int j = 1 ; j <= S_len; ++j)
            {
                if(inputF[i - 1] == inputS[j - 1])
                {
                    memory[i][j] = memory[i-1][j-1] + 1;

                } else{
                    memory[i][j] = max(memory[i][j-1] , memory[i][j] = memory[i-1][j]);
                }

            }
        }

        printf("%d\n" , memory[F_len][S_len]);
    }







    return 0;
}