//
// Created by 고승빈 on 2018. 6. 21..
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct node {
    int parent = -1;
    vector<int> children;
} Node;

void dfs(vector<Node>& tree, int cur, int parent) {
    if(tree[cur].parent > 0) {
        return ;
    }

    tree[cur].parent = parent;
    for(vector<int>::iterator iter = tree[cur].children.begin(); iter != tree[cur].children.end(); ++iter) {
        if(*iter != parent) {
            dfs(tree, *iter, cur);
        }

    }

}

int main() {
    int N;
    int inF, inS;
    vector<Node> tree;
    scanf("%d", &N);
    tree.resize(N + 1);
    for (int i = 1; i < N; ++i) {
        scanf("%d %d", &inF, &inS);
        tree[inF].children.push_back(inS);
        tree[inS].children.push_back(inF);
    }

    dfs(tree, 1, 0);
    for (int idx = 2; idx <= N; ++idx) {
        printf("%d\n", tree[idx].parent);
    }

    return 0;
}