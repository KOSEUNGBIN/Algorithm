//
// Created by 고승빈 on 2017. 10. 9..
//

#include <iostream>
#include <vector>
using namespace std;


int N;
int input , excludeIn;
int root;

vector<vector<int>> Tree;

int preOrder(int parentNum , int nodeNum , int excludeNum);

int main()
{
    scanf("%d" , &N);
    Tree.assign(N , vector<int>());


    for(int i = 0 ; i < N ; ++i)
    {
        scanf("%d" , &input);

        if(input == -1) root = i;
        else
            Tree[input].push_back(i);

    }

    scanf("%d", &excludeIn);



    printf("%d\n", preOrder( -1 , root , excludeIn));

    return 0;
}

int preOrder(int parentNum , int nodeNum , int excludeNum)
{
    int tot = 0;
    if(excludeNum == nodeNum)
    {
        if(Tree[parentNum].size() == 1)
        {
            return 1;
        }

        return 0;
    }

    if(Tree[nodeNum].empty()) return 1;

    for(vector<int>::iterator iter = Tree[nodeNum].begin() ; iter != Tree[nodeNum].end() ; ++iter)
    {
        tot += preOrder(nodeNum , *iter , excludeNum);
    }

    return tot;
}