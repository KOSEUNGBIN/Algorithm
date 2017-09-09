//
// Created by 고승빈 on 2017. 9. 5..
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n , m;
int sour , dest , cost;
vector<vector<int>> city;


int main()
{
    scanf("%d %d" , &n , &m);

    city.assign(n+1 , vector<int>(n+1 , 100001));

    for(int i = 1 ; i <= m ; ++i)
    {
        scanf("%d %d %d",&sour , &dest , &cost);

        city[sour][dest] = (city[sour][dest] > cost ? cost : city[sour][dest]);
    }

    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= n ; ++j)
        {
            for(int k = 1 ; k <= n ;++k)
            {
                city[j][k] = min(city[j][k] , city[j][i] + city[i][k]);
            }
        }
    }

    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= n ; ++j)
        {
           printf("%d ", ( i == j ? 0 : city[i][j]));
        }

        printf("\n");
    }

    return 0;
}