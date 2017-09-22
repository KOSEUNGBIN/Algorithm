//
// Created by 고승빈 on 2017. 9. 21..
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll N , M;
ll  Left , Right , Mid;
ll temp , result;
vector<ll> Tree;

int main()
{
//    input & declare
    scanf("%lld %lld" , &N , &M);

    Tree.resize(N+1);

    for(int i = 1 ; i <= N; ++i)
    {
        scanf("%lld" , &Tree[i]);
    }

//    sorting
    sort(Tree.begin() + 1 , Tree.end());

    Left = 1 ; Right = Tree[N];

//    이분 탐색
    result = 0;
    while(Left <= Right)
    {
        Mid = (Left + Right) / 2;
        temp = 0;
        for(ll i = 1 ; i <= N; ++i )
        {
            if(Tree[i] > Mid)
                temp += (Tree[i] - Mid);
        }

        if(temp >= M)
        {
            result = max( result , Mid );
            Left = Mid + 1;
        }
        else
        {
            Right = Mid - 1;
        }


    }

    printf("%lld\n" , result);

    return 0;
}

