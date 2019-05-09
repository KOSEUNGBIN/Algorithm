//
// Created by 고승빈 on 2019-05-07.
//

#include <iostream>

#define MAX_SIZE 101

using namespace std;

class Node {
private:
    int r;
    int c;
    int speed;
    int direct;
    int size;

public:
    Node(int r, int c, int speed, int direct, int size) : r(r), c(c), speed(speed), direct(direct), size(size) {}

    Node *nextPoint(int nextR, int nextC, int nextDirect, int remainDistance, int R, int C) {
        if (remainDistance <= 0) {
            return new Node(nextR, nextC, speed, nextDirect, size);

        }

        if (nextDirect == 1) {
            if (nextR - 1 <= remainDistance) {
                return nextPoint(1, nextC, 2, remainDistance - (nextR - 1), R, C);

            } else {
                return nextPoint(nextR - remainDistance, nextC, 1, remainDistance - (nextR - 1), R, C);

            }

        } else if (nextDirect == 2) {
            if (R - nextR <= remainDistance) {
                return nextPoint(R, nextC, 1, remainDistance - (R - nextR), R, C);

            } else {
                return nextPoint(nextR + remainDistance, nextC, 2, remainDistance - (R - nextR), R, C);

            }

        } else if (nextDirect == 3) {
            if (C - nextC <= remainDistance) {
                return nextPoint(nextR, C, 4, remainDistance - (C - nextC), R, C);

            } else {
                return nextPoint(nextR, nextC + remainDistance, 3, remainDistance - (C - nextC), R, C);

            }

        } else {
            if (nextC - 1 <= remainDistance) {
                return nextPoint(nextR, 1, 3, remainDistance - (nextC - 1), R, C);

            } else {
                return nextPoint(nextR, nextC - remainDistance, 4, remainDistance - (nextC - 1), R, C);

            }

        }

    }

    int getSize() {
        return size;

    }

    int getR() {
        return r;

    }

    int getC() {
        return c;

    }

    int getDirect() {
        return direct;

    }

    int getSpeed() {
        return speed;

    }

};

Node *board[MAX_SIZE][MAX_SIZE][MAX_SIZE];

void move(int round, int R, int C) {
    int prevRound = round - 1;
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            if (board[prevRound][r][c] != 0) {
                Node *newNode = board[prevRound][r][c]->nextPoint(r, c, board[prevRound][r][c]->getDirect(),
                                                                  board[prevRound][r][c]->getSpeed(), R, C);
                if ((board[round][newNode->getR()][newNode->getC()] == 0) ||
                    ((board[round][newNode->getR()][newNode->getC()] != 0) &&
                     (board[round][newNode->getR()][newNode->getC()]->getSize() < newNode->getSize()))) {
                    board[round][newNode->getR()][newNode->getC()] = newNode;

                }

            }

        }

    }

}

int hold(int col, int R) {
    int round = col - 1;
    for (int r = 1; r <= R; ++r) {
        if (board[round][r][col] != 0) {
            int size = board[round][r][col]->getSize();
            board[round][r][col] = 0;
            return size;

        }

    }

    return 0;

}

int find(int R, int C) {
    int totalSize = 0;
    for (int c = 1; c <= C; ++c) {
        totalSize += hold(c, R);
        move(c, R, C);

    }

    return totalSize;

}

int main() {
    int R, C, M;
    cin >> R >> C >> M;

    int round = 0;
    int r, c, s, d, z;
    for (int m = 0; m < M; ++m) {
        cin >> r >> c >> s >> d >> z;
        board[round][r][c] = new Node(r, c, s, d, z);

    }

    cout << find(R, C) << endl;
    return 0;

}