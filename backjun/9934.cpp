//
// Created by 고승빈 on 2018. 6. 8..
//

#include <iostream>
#include <cmath>
using namespace std;

void travelsalPreorder(int *tree, int depth, int cur) {
    if(depth < cur) return;
    int size = pow(2, cur);
    int start = pow(2, depth - cur);
    int count = 2 * start;
    for(int s = 0; s < size; ++s){
        printf("%d ", tree[start + s * count]);
    }

    printf("\n");
    travelsalPreorder(tree, depth, cur + 1);
}



int main() {
    int depth;
    int *tree;
    int size;
    scanf("%d", &depth);
    size = pow(2, depth) - 1;
    tree = new int[size + 1];
    for(int i = 1; i <= size; ++i) {
        scanf("%d", &tree[i]);
    }

    travelsalPreorder(tree, depth - 1, 0);
    return 0;
}