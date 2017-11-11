//
// Created by 고승빈 on 2017. 11. 11..
//

#include <iostream>
using namespace std;

/*
 * current_node : 현재 노드 번호
 * current_left, current_right : 현재 노드의 범위
 * wanted_left, wanted_right: 구하고자 하는 범위
 *
 * */
int search(const int * tree ,int current_node, int current_left , int current_right, int wanted_left , int wanted_right)
{
    if(current_right < wanted_left ||  wanted_right < current_left)
    {
        return 0;
    }

    if(wanted_left <= current_left && current_right <= wanted_right)
    {
        return tree[current_node];
    }

    int leftChild =  search(tree , 2 * current_node , current_left , (current_left + current_right) / 2 , wanted_left , wanted_right);

    int rightChild =  search(tree , 2 * current_node + 1 , (current_left + current_right) / 2 + 1 , current_right , wanted_left , wanted_right);

    return leftChild + rightChild;
}

/*
 * current_node : 현재 노드 번호
 * current_left, current_right : 현재 노드의 범위
 * index : 변경하는 인덱스(리프 노드)
 *
 * */
void update(int * tree ,int current_node, int current_left , int current_right, int index ,int diff)
{
    if( index < current_left || current_right < index )
    {
        return ;
    }

    tree[current_node] += diff;

    if(current_left != current_right)
    {
        update(tree , 2 * current_node , current_left , (current_left + current_right) / 2 , index , diff);
        update(tree , 2 * current_node + 1 , (current_left + current_right) / 2 + 1 , current_right , index , diff);
    }
}

int main()
{
    int N;
    int tree_size;
    int result;
    int * segment_tree;

    N = (1 << N);



    tree_size = 2 * N - 1;
    segment_tree = new int[tree_size + 1];

    update(segment_tree , 1 , 0 , N - 1 , 1 , 10);
    update(segment_tree , 1 , 0 , N - 1 , 2 , 4);

    result = search(segment_tree , 1 , 0 , N - 1 , 1 ,4);

    cout << "result = " << result << endl;
}


