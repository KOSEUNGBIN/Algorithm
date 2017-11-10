//
// Created by 고승빈 on 2017. 10. 18..
//

#include <iostream>
#include <string.h>
#define DIV 10
using namespace std;

bool check[10001];
int  tmp , oper;

int main()
{

    memset(check , false , 10001);

    for(int cur = 1 ;cur < 10001 ; ++cur)
    {
        tmp = cur;
        oper = 0;
        while(tmp > 0)
        {
            oper += (tmp % DIV);
            tmp /= DIV;
        }

        check[cur + oper] = true;
    }

    for(int i = 1; i <= 10000 ; ++i)
    {
        if(!check[i])   printf("%d\n" , i);
    }

    return 0;
}