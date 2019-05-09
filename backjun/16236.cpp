//
// Created by 고승빈 on 2019-05-09.
//

#include <iostream>
#include <queue>

#define MAX_LENGTH 20
#define EMPTY 0
#define MAX_DIRECT 4

using namespace std;

int space[MAX_LENGTH][MAX_LENGTH];
bool visit[MAX_LENGTH][MAX_LENGTH];

int dy[MAX_DIRECT] = {1, -1, 0, 0};
int dx[MAX_DIRECT] = {0, 0, 1, -1};

class Node {
private:
    int y;
    int x;
    int count;

public:
    Node(int y, int x, int count) {
        this->y = y;
        this->x = x;
        this->count = count;

    }

    int getY() const {
        return y;
    }

    int getX() const {
        return x;
    }

    int getCount() const {
        return count;
    }

    void initCount() {
        count = 0;
    }

};

bool isRange(int y, int x, int N) {
    return (0 <= y && y < N) && (0 <= x && x < N);

}

bool enablePass(int y, int x, int size) {
    return space[y][x] <= size;

}

bool isPossible(int y, int x, int size) {
    return 0 < space[y][x] && space[y][x] < size;

}

bool isMinimum(Node *next, Node *min) {
    if (min == EMPTY) { return true; }

    bool less = next->getCount() < min->getCount();
    bool equal = next->getCount() == min->getCount();
    bool lessY = next->getY() < min->getY();
    bool equalY = next->getY() == min->getY();
    bool lessX = next->getX() < min->getX();
    return less || (equal && lessY) || (equal && equalY && lessX);

}

void eat(Node *node) {
    if (node != EMPTY) {
        space[node->getY()][node->getX()] = 0;

    }

}

Node *move(Node *begin, int size, int N) {
    queue<Node *> que;
    que.push(begin);
    Node *minNode = EMPTY;
    visit[begin->getY()][begin->getX()] = true;
    while (!que.empty()) {
        Node *node = que.front();
        for (int direct = 0; direct < MAX_DIRECT; ++direct) {
            int nextY = node->getY() + dy[direct];
            int nextX = node->getX() + dx[direct];
            if (isRange(nextY, nextX, N) && !visit[nextY][nextX] && enablePass(nextY, nextX, size)) {
                visit[nextY][nextX] = true;
                Node *nextNode = new Node(nextY, nextX, node->getCount() + 1);
                if (isPossible(nextY, nextX, size) && isMinimum(nextNode, minNode)) {
                    minNode = nextNode;

                } else {
                    que.push(nextNode);

                }

            }

        }

        que.pop();

    }

    eat(minNode);
    return minNode;

}

void clear(int N) {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            visit[y][x] = false;

        }

    }

}

int solve(int y, int x, int N) {
    int size = 2;
    int time = 0;
    int count = 0;

    Node *node = new Node(y, x, 0);
    while ((node = move(node, size, N)) != EMPTY) {
        time += node->getCount();
        node->initCount();
        if (++count >= size) {
            ++size, count = 0;

        }

        clear(N);

    }

    return time;

}

int main() {
    int N;
    cin >> N;

    int startY = 0;
    int startX = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> space[y][x];
            if (space[y][x] == 9) {
                space[y][x] = 0;
                startY = y;
                startX = x;

            }

        }

    }

    cout << solve(startY, startX, N) << endl;
    return 0;

}