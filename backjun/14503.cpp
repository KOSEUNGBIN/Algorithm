//
// Created by 고승빈 on 2018. 9. 9..
//

#include <iostream>
using namespace std;

typedef struct robot {
    int r;
    int c;
    int d;
} Robot;

int N, M;
int r, c, d;
int counts = 0;
int room[51][51];

int directionRow [] = {-1, 0, 1, 0};
int directionCol [] = {0, 1, 0, -1};

int reverseDirectionRow [] = {1, 0, -1, 0};
int reverseDirectionCol [] = {0, -1, 0, 1};

bool clean(Robot robot);

int main() {
    cin >> N >> M;
    cin >> r >> c >> d;

    for(int n = 0; n < N; ++n) {
        for(int m = 0; m < M; ++m) {
            cin >> room[n][m];

        }

    }

    clean({r, c, d});
    cout << counts << "\n";

    return 0;

}

bool isOutOfRange(int r, int c) {
    return r < 0 || r >= N || c < 0 || c >= M;

}

bool isCleaned(int r, int c) {
    return room[r][c] == 2;

}

bool isWall(int r, int c) {
    return room[r][c] == 1;

}

bool isStop(Robot robot) {
    return robot.d == -1 && robot.r == -1 && robot.c == -1;

}

int rotate(int direction) {
    return (direction + 3) % 4;

}

Robot changeCoordination(Robot robot) {
    return {
            robot.r + directionRow[robot.d]
            ,robot.c + directionCol[robot.d]
            ,robot.d
    };

}

Robot changeBackWordCoordination(Robot robot) {
    return {
            robot.r + reverseDirectionRow[robot.d]
            ,robot.c + reverseDirectionCol[robot.d]
            ,robot.d
    };

}

Robot move(Robot robot) {
    int newDirection = robot.d;
    Robot origin = robot;

    for(int i = 1; i <= 4; ++i) {
        newDirection = rotate(newDirection);
        robot.d = newDirection;
        Robot moved = changeCoordination(robot);

        if(!(isOutOfRange(moved.r, moved.c) || isCleaned(moved.r, moved.c) || isWall(moved.r, moved.c))) {
            return moved;

        }

    }

    Robot reversed = changeBackWordCoordination(origin);
    if(isOutOfRange(reversed.r, reversed.c) || isWall(reversed.r, reversed.c)) {
        return {-1,-1,-1};

    }

    return reversed;

}



bool clean(Robot robot) {
    if(isOutOfRange(robot.r, robot.c)) return false;
    if(room[robot.r][robot.c] == 0) {
        room[robot.r][robot.c] = 2;
        counts++;

    }

    Robot moveRobot = move(robot);
    if (!isStop(moveRobot)) {
        return clean(moveRobot);

    }

    return false;

}