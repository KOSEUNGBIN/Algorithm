//
// Created by 고승빈 on 2017. 11. 13..
//

#include <iostream>
#include <vector>
#include <utility>
#include <limits.h>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N , M;
ll tree_size;
ll a , b;
ll idx;
vector<pair<ll,ll>> tree;

ll init(ll node, ll start, ll end , bool isMin);
ll  search(ll node , ll start , ll end , ll left , ll right, bool isMin);

int main()
{
    scanf("%lld %lld" , &N , &M);


    idx = tree_size = 1;
    while(tree_size < N)   tree_size *= 2;


    tree.assign(2 * tree_size + 1, make_pair(INT_MAX,INT_MIN));


    for(int i = 0  ; i <  N  ; ++i) {

        scanf("%lld", &tree[tree_size + i].first);
        tree[tree_size + i].second = tree[tree_size + i].first;

    }

    init(1 , 0 , tree_size - 1,  true);
    init(1 , 0 , tree_size - 1,  false);

    for(int i = 1; i <= M ; ++i)
    {
        scanf("%lld %lld", &a , &b);
        printf("%lld %lld\n" , search(1 , 0 , tree_size - 1 , a - 1 , b - 1 , true) , search(1 , 0 , tree_size - 1 , a - 1 , b - 1 , false));
    }

    return 0;
}

ll init(ll node, ll start, ll end , bool isMin)
{
    if(start == end)
    {
        return isMin ? tree[node].first : tree[node].second;
    }

    if(isMin)
    {
        return tree[node].first = min(init(2 * node , start , (start + end) / 2 , isMin) , init(2 * node + 1, (start + end) / 2 + 1 , end , isMin));
    } else{
        return tree[node].second = max(init(2 * node , start , (start + end) / 2 , isMin) , init(2 * node + 1, (start + end) / 2 + 1 , end, isMin));
    }

}

ll search(ll node , ll start , ll end , ll left , ll right, bool isMin)
{
    if( right < start || left > end)    return isMin ? INT_MAX : INT_MIN;

    if(left <= start && end <= right)   return isMin ? tree[node].first : tree[node].second;

    if(isMin)
    {
        return min(search(2 * node , start , (start + end) / 2 ,left , right, isMin) , search(2 * node + 1, (start + end) / 2 + 1 , end,left , right, isMin));
    } else{
        return max(search(2 * node , start , (start + end) / 2 ,left , right, isMin) , search(2 * node + 1, (start + end) / 2 + 1 , end,left , right, isMin));
    }
}
