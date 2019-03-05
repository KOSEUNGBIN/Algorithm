//
// Created by 고승빈 on 2019. 3. 5..
//

#include <iostream>
#include <queue>


#define RED 'R'
#define BLUE 'B'
#define HOLE 'O'
#define TACKLE '#'

#define LIMIT 11
#define MAX_DIR 4
#define MAX_SIZE 10

using namespace std;

int dx[MAX_DIR] = {1, 0, -1, 0};
int dy[MAX_DIR] = {0, 1, 0, -1};

int N, M;
char board[MAX_SIZE][MAX_SIZE];

class Ball {
private:
    int x, y;

public:
    Ball() {}

    Ball(Ball *ball) {
        this->x = ball->getX();
        this->y = ball->getY();

    }

    Ball(int x, int y) {
        this->x = x;
        this->y = y;

    }

    int getX() {
        return x;

    }

    void setX(int x) {
        this->x = x;

    }

    int getY() {
        return y;

    }

    void setY(int y) {
        this->y = y;

    }

    void move(int direction) {
        y += dy[direction];
        x += dx[direction];

    }

    void movePrev(int direction) {
        y -= dy[direction];
        x -= dx[direction];

    }

};

class BallGroup {
private:
    Ball *red;
    Ball *blue;
    int turnCount;

public:
    BallGroup() {}

    BallGroup(Ball *red, Ball *blue, int N, int M, int turnCount) {
        this->red = red;
        this->blue = blue;
        this->turnCount = turnCount;

    }

    void setRed(Ball *red) {
        this->red = red;

    }

    void setBlue(Ball *blue) {
        this->blue = blue;

    }

    Ball *getRed() {
        return red;

    }

    Ball *getBlue() {
        return blue;

    }

    int getCount() {
        return turnCount;

    }

};

bool **makeVisits(int N, int M) {
    bool **states = new bool *[N];
    for (int n = 0; n < N; ++n) {
        states[n] = new bool[M];

    }

    return states;

}

bool isRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;

}

bool isPossible(int y, int x) {
    return isRange(y, x) && board[y][x] != TACKLE;

}

bool isEquals(Ball *a, Ball *b) {
    return a->getY() == b->getY() && a->getX() == b->getX();

}

Ball *move(Ball *ball, int direction) {
    Ball *next = new Ball(ball);
    while (isPossible(next->getY() + dy[direction], next->getX() + dx[direction])) {
        next->move(direction);

    }

    return next;

}

int distance(Ball *next, Ball *prev) {
    return abs(next->getX() - prev->getX()) + abs(next->getY() - prev->getY());

}


bool isPossibleEnter(Ball *next, Ball *prev, Ball *hole) {
    return min(next->getX(), prev->getX()) <= hole->getX() && hole->getX() <= max(next->getX(), prev->getX())
           && min(next->getY(), prev->getY()) <= hole->getY() && hole->getY() <= max(next->getY(), prev->getY());

}

BallGroup *nextBallGroup(BallGroup *ballGroup, int direction, bool **redVisits, bool **blueVisits, Ball &hole) {
    if (ballGroup->getCount() + 1 >= LIMIT) {
        return 0;

    }

    Ball *nextBlue = move(ballGroup->getBlue(), direction);
    Ball *nextRed = move(ballGroup->getRed(), direction);
    if (((isEquals(nextRed, ballGroup->getRed()) && isEquals(nextBlue, ballGroup->getBlue()))
         || (redVisits[nextRed->getY()][nextRed->getX()] && blueVisits[nextBlue->getY()][nextBlue->getX()]))
        || isPossibleEnter(nextBlue, ballGroup->getBlue(), &hole)) {
        return 0;

    }

    if (isEquals(nextBlue, nextRed)) {
        if (distance(nextRed, ballGroup->getRed()) < distance(nextBlue, ballGroup->getBlue())) {
            nextBlue->movePrev(direction);

        } else {
            nextRed->movePrev(direction);

        }

    }

    return new BallGroup(nextRed, nextBlue, N, M, ballGroup->getCount() + 1);

}

void checkVisit(bool **visits, Ball *ball) {
    visits[ball->getY()][ball->getX()] = true;

}

int bfs(Ball red, Ball blue, Ball hole) {
    BallGroup ballGroup(&red, &blue, N, M, 0);
    queue<BallGroup *> que;
    que.push(&ballGroup);

    bool **redVisits = makeVisits(N, M);
    bool **blueVisits = makeVisits(N, M);
    checkVisit(redVisits, ballGroup.getRed());
    checkVisit(blueVisits, ballGroup.getBlue());

    int minimum = LIMIT;
    while (!que.empty()) {
        BallGroup *currentGroup = que.front();
        BallGroup *nextGroup;
        for (int dir = 0; dir < MAX_DIR; ++dir) {
            if ((nextGroup = nextBallGroup(currentGroup, dir, redVisits, blueVisits, hole)) == 0) {
                continue;

            }

            checkVisit(redVisits, ballGroup.getRed());
            checkVisit(blueVisits, ballGroup.getBlue());
            if (isPossibleEnter(nextGroup->getRed(), currentGroup->getRed(), &hole)) {
                // 해당 움직인 카운트 최소값 비교
                minimum = min(minimum, nextGroup->getCount());
                break;

            }

            que.push(nextGroup);

        }

        que.pop();

    }

    return minimum == LIMIT ? -1 : minimum;

}

int main() {
    cin >> N >> M;

    Ball red, blue, hole;
    string input;
    for (int n = 0; n < N; ++n) {
        cin >> input;
        for (int m = 0; m < M; ++m) {
            board[n][m] = input.at(m);
            if (input.at(m) == RED) {
                red.setX(m);
                red.setY(n);

            } else if (input.at(m) == BLUE) {
                blue.setX(m);
                blue.setY(n);

            } else if (input.at(m) == HOLE) {
                hole.setX(m);
                hole.setY(n);

            }

        }

    }

    cout << bfs(red, blue, hole) << "\n";
    return 0;

}