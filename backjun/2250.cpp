//
// Created by 고승빈 on 2018. 6. 21..
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef struct node {
    int left = -1;
    int right = -1;
    int parent = -1;
    int weight = 1;
} Node;

int travelsal(vector<Node> &tree, vector<pair<int, int>> &dep, int left, int right, int cur, int depth);

int main() {
    int N, root;
    int inLeft, inRight, inCur;
    vector<Node> tree;
    vector<pair<int, int>> dep;
    vector<int> leafNodes;
    scanf("%d", &N);
    tree.resize(N + 1);
    dep.resize(N + 1, make_pair(N + 1, 0));
    for (int i = 1; i <= N; ++i) {
        scanf("%d %d %d", &inCur, &inLeft, &inRight);
        tree[inCur].left = inLeft;
        tree[inCur].right = inRight;
        if (inLeft > 0) {
            tree[inLeft].parent = inCur;
        }

        if (inRight > 0) {
            tree[inRight].parent = inCur;
        }

        if (inLeft < 0 && inRight < 0) {
            leafNodes.push_back(inCur);
        }

    }

    for (int i = 1; i <= N; ++i) {
        if (tree[i].parent == -1) {
            root = i;
            break;
        }

    }


    for (vector<int>::iterator iter = leafNodes.begin(); iter != leafNodes.end(); ++iter) {
        int cur = *iter;
        int parent = tree[cur].parent;
        int chg = tree[cur].weight;
        while (cur != -1) {
            if (tree[parent].weight == 1) {
                tree[parent].weight += tree[cur].weight;
                chg = tree[parent].weight;
            } else {
                tree[parent].weight += chg;
            }

            cur = parent;
            parent = tree[cur].parent;

        }

    }

    int depth = travelsal(tree, dep, 0, N + 1, root, 1);
    int maxIdx = 1;
    int maximum = dep[maxIdx].second - dep[maxIdx].first + 1;
    for (int idx = 2; idx <= depth; ++idx) {
        if (maximum < dep[idx].second - dep[idx].first + 1) {
            maxIdx = idx;
            maximum = dep[idx].second - dep[idx].first + 1;
        }

    }

    printf("%d %d\n", maxIdx, maximum);
    return 0;
}

int travelsal(vector<Node> &tree, vector<pair<int, int>> &dep, int left, int right, int cur, int depth) {
    if (tree[cur].left <= 0 && tree[cur].right <= 0) {
        dep[depth].first = min(dep[depth].first, left + 1);
        dep[depth].second = max(dep[depth].second, left + 1);
        return depth;

    } else if (tree[cur].left > 0 && tree[cur].right > 0) {
        dep[depth].first = min(dep[depth].first, left + tree[tree[cur].left].weight + 1);
        dep[depth].second = max(dep[depth].second, right - tree[tree[cur].right].weight - 1);
        return max(travelsal(tree, dep, left, left + tree[tree[cur].left].weight + 1, tree[cur].left, depth + 1),
                   travelsal(tree, dep, right - tree[tree[cur].right].weight - 1, right, tree[cur].right, depth + 1));

    } else if (tree[cur].left > 0) {
        dep[depth].first = min(dep[depth].first, left + tree[tree[cur].left].weight + 1);
        dep[depth].second = max(dep[depth].second, left + tree[tree[cur].left].weight + 1);
        return travelsal(tree, dep, left, left + tree[tree[cur].left].weight + 1, tree[cur].left, depth + 1);

    } else {
        dep[depth].first = min(dep[depth].first, right - tree[tree[cur].right].weight - 1);
        dep[depth].second = max(dep[depth].second, right - tree[tree[cur].right].weight - 1);
        return travelsal(tree, dep, right - tree[tree[cur].right].weight - 1, right, tree[cur].right, depth + 1);

    }

}