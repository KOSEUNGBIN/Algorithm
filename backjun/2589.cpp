//
// Created by 고승빈 on 2018. 10. 2..
//

#include <iostream>
#include <vector>
#include <queue>
#define LAND 'L'
#define SEA 'W'

using namespace std;

int operatorR[4] = {-1 , 1 , 0 , 0};
int operatorC[4] = {0 , 0 , -1 , 1};


class Node {
private:
    int r;
    int c;
    int time;

public:
    Node(int r, int c, int time) : r(r), c(c), time(time) {}

    int getR() const {
        return r;
    }

    void setR(int r) {
        Node::r = r;
    }

    int getC() const {
        return c;
    }

    void setC(int c) {
        Node::c = c;
    }

    int getTime() const {
        return time;
    }

    void setTime(int time) {
        Node::time = time;
    }

};

Node* makeNode(int r, int c, int time) {
    return new Node(r, c, time);

}

void bfs(Node* node, vector<vector<char>>* map, vector<vector<bool>>* cache, queue<Node*>* que) {
    int boundR = map->size() - 1;
    int boundC = (*map)[0].size() - 1;

    for(int op = 0; op < 4; ++op) {
        bool isNotOutOfRange = node->getR() + operatorR[op] > 0 && node->getR() + operatorR[op] <= boundR && node->getC() + operatorC[op] > 0 && node->getC() + operatorC[op] <= boundC;
        if(isNotOutOfRange) {
            bool isPassed = (*cache)[node->getR() + operatorR[op]][node->getC() + operatorC[op]];
            bool isLand = (*map)[node->getR() + operatorR[op]][node->getC() + operatorC[op]] == LAND;
            if(isLand && !isPassed) {
                (*cache)[node->getR() + operatorR[op]][node->getC() + operatorC[op]] = true;
                que->push(makeNode(node->getR() + operatorR[op], node->getC() + operatorC[op], node->getTime() + 1));

            }
        }

    }

}

int search(int r, int c, vector<vector<char>> map) {
    if(map[r][c] == SEA) {
        return 0;

    }

    vector<vector<bool>> cache(map.size(), vector<bool>(map[0].size(), false));
    cache[r][c] = true;

    Node node(r, c, 0);
    queue<Node*> que;
    que.push(&node);

    int maximum = 0;
    while(!que.empty()) {
        Node* poped = que.front();
        que.pop();
        if(poped->getTime() > maximum) {
            maximum = poped->getTime();

        }

        bfs(poped, &map, &cache, &que);


    }

    return maximum;

}

int main() {
    int R, C;
    vector<vector<char>> map;

    cin >> R >> C;

    map.assign(R + 1, vector<char>(C + 1));
    for(int r = 1; r <= R; ++r) {
        for(int c = 1; c <= C; ++c) {
            cin >> map[r][c];

        }

    }

    int maximum = 0;
    for(int r = 1; r <= R; ++r) {
        for(int c = 1; c <= C; ++c) {
            int result = search(r, c, map);
            if(result > maximum) {
                maximum = result;

            }

        }

    }

    cout << maximum << "\n";

    return 0;

}