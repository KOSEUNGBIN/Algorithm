//
// Created by 고승빈 on 2019. 1. 9..
//

#include <iostream>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

int H_MOVE[4] = {1, -1, 0, 0};
int W_MOVE[4] = {0, 0, 1, -1};

class Node {
private :
    int h;
    int w;
    int state;
    int time;
public:
    Node(int h, int w, int state, int time) : h(h), w(w), state(state), time(time) {}

    int getH() const {
        return h;
    }

    int getW() const {
        return w;
    }

    int getState() const {
        return state;
    }

    int getTime() const {
        return time;
    }

};


bool isInner(int h, int w, int H, int W) {
    return (0 <= h && h < H) && (0 <= w && w < W);

}


Node *bfs(int **companies, bool **visit, Node *spot, int H, int W) {
    queue<Node *> que;
    que.push(spot);
    Node *cur;
    while (!que.empty()) {
        cur = que.front();
        for (int d = 0; d < 4; ++d) {
            int nextH = cur->getH() + H_MOVE[d];
            int nextW = cur->getW() + W_MOVE[d];
            if (isInner(nextH, nextW, H, W) && !visit[nextH][nextW]) {
                if (companies[nextH][nextW] > 0 && cur->getState() >= companies[nextH][nextW]) {
                    Node *result = new Node(nextH, nextW, cur->getState() + 1, cur->getTime() + 1);
                    companies[nextH][nextW] = 0;
                    return result;

                } else if (companies[nextH][nextW] >= 0) {
                    visit[nextH][nextW] = true;
                    que.push(new Node(nextH, nextW, cur->getState(), cur->getTime() + 1));

                }

            }

        }

        que.pop();

    }

    return NULL;

}


bool **makeVisits(int H, int W) {
    bool **visits = new bool *[H];
    for (int n = 0; n < H; ++n) {
        visits[n] = new bool[W]{false,};

    }

    return visits;

}


int search(int **companies, Node *start, int H, int W, int N) {
    int result = start->getTime();
    while (start != NULL && start->getState() <= N) {
        start = bfs(companies, makeVisits(H, W), start, H, W);
        if (start != NULL) {
            result += start->getTime();
            start = new Node(start->getH(), start->getW(), start->getState(), 0);

        }

    }

    return result;

}


Node *input(int **companies, int H, int W) {
    Node *start;
    string str;
    for (int h = 0; h < H; ++h) {
        cin >> str;
        companies[h] = new int[W];
        for (int w = 0; w < W; ++w) {
            if (str.at(w) == '.') {
                companies[h][w] = 0;

            } else if (str.at(w) == 'X') {
                companies[h][w] = -1;

            } else if (str.at(w) == 'S') {
                companies[h][w] = 0;
                start = new Node(h, w, 1, 0);

            } else {
                companies[h][w] = str.at(w) - '0';

            }

        }

    }

    return start;

}


int main() {
    int H, W, N;
    cin >> H >> W >> N;
    int **companies = new int *[H];
    Node *start = input(companies, H, W);
    cout << search(companies, start, H, W, N) << "\n";
    return 0;

}