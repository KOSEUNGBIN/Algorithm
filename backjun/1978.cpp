//
// Created by 고승빈 on 2017. 9. 26..
//

#include <iostream>
#include <string.h>
using namespace std;

int N , cnt , maximum;
int arr[101];
bool check[1001];

int main()
{
    scanf("%d" , &N);
    cnt = 0;

    memset(check , 0 , 1001);

    for(int i = 0 ; i < N; ++i)
    {
        scanf("%d" , &arr[i]);
    }

    check[0] = check[1] = true;

    for(int i = 2 ; i <= 1000 ; ++i)
    {
        if(check[i]) continue;

        for(int j = 2 ; j * i <= 1000 ; ++j)
        {
            check[j * i] = true;
        }
    }



    for(int i = 0 ; i < N ; ++i) {

        if(!check[arr[i]] )   ++cnt;
    }


    printf("%d\n" , cnt);

    return 0;
}