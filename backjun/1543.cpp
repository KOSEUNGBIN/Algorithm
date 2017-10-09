//
// Created by 고승빈 on 2017. 10. 7..
//

#include <iostream>
#include <string.h>
using namespace std;

char documents[3000] , cmp[100];

int main()
{
    int documents_len , cmp_len;
    int j , cnt;

    fgets(documents ,3000 , stdin);
    fgets(cmp ,100, stdin);

    documents_len = strlen(documents);
    cmp_len = strlen(cmp);

    --documents_len;    --cmp_len;
    cnt = 0;

    for(int i = 0 ; i < documents_len ; )
    {
        if(cmp[0] == documents[i])
        {
            for(j = 1 ; j < cmp_len; ++j)
            {
                if(cmp[j] != documents[i + j])  break;
            }

            if(j == cmp_len)
            {
                ++cnt;
                i += cmp_len;
            } else{
                ++i;
            }
        }
        else
        {
            ++i;
        }
    }

    printf("%d\n" , cnt);

    return 0;
}