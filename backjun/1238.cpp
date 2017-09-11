//
// Created by 고승빈 on 2017. 9. 11..
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define Maximum 1000001



int N , M ,X;
int sour , dest , dur;
int resultPerson , resultValue = 0;
vector<vector<int>> city;

int main()
{
    scanf("%d %d %d" , &N , &M , &X);

//   declare
    city.assign(N+1 , vector<int>(N+1 , Maximum));

//    input
    for(int i = 1 ; i <= M ; ++i)
    {
        scanf("%d %d %d" , &sour , &dest , &dur);

        city[sour][dest] = dur;
    }

//    플로이드 워셜
    for(int pass = 1 ; pass <= N ; ++pass)
    {
        for(int start = 1 ; start <= N ; ++start)
        {
            city[start][start] = 0;

            if(city[start][pass] < Maximum)
            {
                for(int end = 1 ; end <= N ; ++end)
                {
                    city[start][end] = min(city[start][end], city[start][pass] + city[pass][end]);
                }
            }
        }
    }

//    check
    for(int i = 1 ; i <= N ; ++i)
    {
        if(resultValue < city[i][X] + city[X][i])
        {
            resultValue = city[i][X] + city[X][i];
            resultPerson = i;
        }
    }

    printf("%d\n" , resultValue);

    return 0;
}