//
// Created by 고승빈 on 2018. 4. 7..
//

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

typedef struct node {
    int x, y, order;
} Order;

void checkNight(queue<Order>& ordered, int board[300][300], Order& cur, int l);

int main() {
    int T;
    int l;
    Order start, end;
    Order cur;
    int board[300][300];
    queue<Order> ordered;

    scanf("%d", &T);

    while(T--) {
        scanf("%d", &l);
        scanf("%d %d", &start.x, &start.y);
        scanf("%d %d", &end.x, &end.y);

        start.order = end.order = 0;
        ordered.push(start);
        memset(board, INT8_MAX, 300*300*sizeof(int));

        do {
            cur = ordered.front();
            if(cur.x == end.x && cur.y == end.y) {
                if(cur.order < board[cur.x][cur.y]) {
                    board[cur.x][cur.y] = cur.order;
                }
            } else {
                if(cur.order < board[cur.x][cur.y]) {
                    board[cur.x][cur.y] = cur.order;
                    checkNight(ordered, board, cur, l);
                }

            }

            ordered.pop();
        } while(!ordered.empty());

        while(!ordered.empty()) {
            cur = ordered.front();
            ordered.pop();
        }

        printf("%d\n", board[end.x][end.y]);
    }



    return 0;
}

void checkNight(queue<Order>& ordered, int board[300][300], Order& cur, int l) {

    if(cur.x - 2 >= 0 && cur.y - 1 >= 0 && cur.order < board[cur.x - 2][cur.y - 1]) {
        Order newNode;
        newNode.x = cur.x - 2;
        newNode.y = cur.y - 1;
        newNode.order = cur.order + 1;
        ordered.push(newNode);
    }

    if(cur.x - 1 >= 0 && cur.y - 2 >= 0 && cur.order < board[cur.x - 1][cur.y - 2]) {
        Order newNode;
        newNode.x = cur.x - 1;
        newNode.y = cur.y - 2;
        newNode.order = cur.order + 1;
        ordered.push(newNode);
    }

    if(cur.x + 1 < l && cur.y - 2 >= 0 && cur.order < board[cur.x + 1][cur.y - 2]) {
        Order newNode;
        newNode.x = cur.x + 1;
        newNode.y = cur.y - 2;
        newNode.order = cur.order + 1;
        ordered.push(newNode);
    }

    if(cur.x + 2 < l && cur.y - 1 >= 0 && cur.order < board[cur.x + 2][cur.y - 1]) {
        Order newNode;
        newNode.x = cur.x + 2;
        newNode.y = cur.y - 1;
        newNode.order = cur.order + 1;
        ordered.push(newNode);
    }

    if(cur.x - 2 >= 0 && cur.y + 1 < l && cur.order < board[cur.x - 2][cur.y + 1]) {
        Order newNode;
        newNode.x = cur.x - 2;
        newNode.y = cur.y + 1;
        newNode.order = cur.order + 1;
        ordered.push(newNode);
    }

    if(cur.x - 1 >= 0 && cur.y + 2 < l && cur.order < board[cur.x - 1][cur.y + 2]) {
        Order newNode;
        newNode.x = cur.x - 1;
        newNode.y = cur.y + 2;
        newNode.order = cur.order + 1;
        ordered.push(newNode);
    }

    if(cur.x + 1 < l && cur.y + 2 < l && cur.order < board[cur.x + 1][cur.y + 2]) {
        Order newNode;
        newNode.x = cur.x + 1;
        newNode.y = cur.y + 2;
        newNode.order = cur.order + 1;
        ordered.push(newNode);
    }

    if(cur.x + 2 < l && cur.y + 1 < l && cur.order < board[cur.x + 2][cur.y + 1]) {
        Order newNode;
        newNode.x = cur.x + 2;
        newNode.y = cur.y + 1;
        newNode.order = cur.order + 1;
        ordered.push(newNode);
    }
}