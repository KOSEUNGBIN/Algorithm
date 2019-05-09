//
// Created by 고승빈 on 2019-05-08.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_LENGTH 10
#define MAX_DIRECT 8

using namespace std;

int ground[MAX_LENGTH][MAX_LENGTH];
int supplements[MAX_LENGTH][MAX_LENGTH];
int breedCounter[MAX_LENGTH][MAX_LENGTH];

vector<int> deadTrees[MAX_LENGTH][MAX_LENGTH];
vector<int> trees[MAX_LENGTH][MAX_LENGTH];

int dy[MAX_DIRECT] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[MAX_DIRECT] = {-1, 0, 1, -1, 1, -1, 0, 1};

void init(int N) {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            ground[y][x] = 5;
            breedCounter[y][x] = 0;

        }

    }

}

void plant(int x, int y, int z, int N) {
    if ((0 <= x && x < N) && (0 <= y && y < N)) {
        trees[y][x].push_back(z);

    }

}

void grow(int y, int x) {
    sort(trees[y][x].begin(), trees[y][x].end());
    vector<int> tree;
    for (int age : trees[y][x]) {
        if (age <= ground[y][x]) {
            ground[y][x] -= age;
            tree.push_back(age + 1);
            if ((age + 1) % 5 == 0) {
                ++breedCounter[y][x];

            }

        } else {
            deadTrees[y][x].push_back(age / 2);

        }

    }

    trees[y][x] = tree;

}

void supply(int y, int x) {
    for (int rest : deadTrees[y][x]) {
        ground[y][x] += rest;

    }

}

void provide(int N) {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            deadTrees[y][x].clear();
            grow(y, x);
            supply(y, x);

        }

    }

}

void breed(int N) {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            for (int d = 0; d <= MAX_DIRECT; ++d) {
                for (int c = 0; c < breedCounter[y][x]; ++c) {
                    plant(x + dx[d], y + dy[d], 1, N);

                }

            }

            breedCounter[y][x] = 0;

        }

    }

}

void supplyGround(int N) {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            ground[y][x] += supplements[y][x];

        }

    }

}

int count(int N) {
    int tot = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            tot += trees[y][x].size();

        }

    }

    return tot;

}

int main() {
//    freopen("/Users/koseungbin/CLionProjects/Algorithm/sample/16235.txt", "r", stdin);

    int N, M, K;
    cin >> N >> M >> K;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> supplements[x][y];

        }

    }

    init(N);
    int x, y, z;
    for (int m = 0; m < M; ++m) {
        cin >> x >> y >> z;
        plant(x - 1, y - 1, z, N);

    }

    for (int k = 0; k < K; ++k) {
        provide(N);
        breed(N);
        supplyGround(N);

    }

    cout << count(N) << endl;
    return 0;

}


/*
#include <iostream>

#define MAX_LENGTH 10
#define EMPTY 0
#define BREED_STANDARD 5
#define MAX_DICECT 8

using namespace std;

class Tree {
private:
    int age;
    Tree *next;
    Tree *prev;

public:
    Tree() {
        this->next = EMPTY;
        this->prev = EMPTY;

    }

    Tree(int age) {
        this->age = age;
        this->next = EMPTY;
        this->prev = EMPTY;

    }

    bool isBigger(int otherAge) {
        return age > otherAge;

    }

    void addNext(int age) {
        if (this->next == EMPTY) {
            this->next = new Tree(age);
            this->next->prev = this;

        } else if (this->next->isBigger(age)) {
            Tree *tree = new Tree(age);
            if (this->next != EMPTY) {
                tree->next = this->next;
                this->next->prev = tree;

            }

            this->next = tree;
            tree->prev = this;

        } else {
            this->next->addNext(age);

        }

    }

    void increaseAge() {
        age++;

    }

    Tree *getNext() {
        return next;

    }

    int getAge() {
        return age;

    }

    bool isEnough(int energy) {
        return age <= energy;

    }

    bool isPossibleBreed() {
        return age % BREED_STANDARD == 0;

    }

    void cutFront() {
        if (this->prev != EMPTY) {
            this->prev->next = EMPTY;
            this->prev = EMPTY;

        }

    }

};

int ground[MAX_LENGTH][MAX_LENGTH];
int supplements[MAX_LENGTH][MAX_LENGTH];
Tree trees[MAX_LENGTH][MAX_LENGTH];

int dy[MAX_DICECT] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[MAX_DICECT] = {-1, 0, 1, -1, 1, -1, 0, 1};

void init(int N) {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            ground[y][x] = 5;

        }

    }

}

void plant(int x, int y, int z, int N) {
    if ((0 <= x && x < N) && (0 <= y && y < N)) {
        trees[y][x].addNext(z);

    }

}

Tree *grow(int y, int x) {
    Tree *tree = trees[y][x].getNext();
    while (tree != EMPTY) {
        if (tree->isEnough(ground[y][x])) {
            ground[y][x] -= tree->getAge();
            tree->increaseAge();

        } else {
            tree->cutFront();
            break;

        }

        tree = tree->getNext();

    }

    return tree;

}

void supply(int y, int x, Tree *dead) {
    Tree *tree = dead;
    while (tree != EMPTY) {
        ground[y][x] += (tree->getAge() / 2);
        tree = tree->getNext();

    }


}

void provide(int N) {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            supply(y, x, grow(y, x));

        }

    }

}

int estimate(int y, int x) {
    int count = 0;
    Tree *tree = trees[y][x].getNext();
    while (tree != EMPTY) {
        if (tree->isPossibleBreed()) { ++count; }
        tree = tree->getNext();

    }

    return count;

}

void breed(int N) {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            int count = estimate(y, x);
            for (int d = 0; d <= MAX_DICECT; ++d) {
                for (int c = 0; c < count; ++c) {
                    plant(x + dx[d], y + dy[d], 1, N);

                }

            }

        }

    }

}

void supplyGround(int N) {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            ground[y][x] += supplements[y][x];

        }

    }

}

int count(int N) {
    int tot = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            Tree *tree = trees[y][x].getNext();
            while (tree != EMPTY) {
                ++tot;
                tree = tree->getNext();

            }

        }

    }

    return tot;

}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> supplements[x][y];

        }

    }

    init(N);
    int x, y, z;
    for (int m = 0; m < M; ++m) {
        cin >> x >> y >> z;
        plant(x - 1, y - 1, z, N);

    }

    for (int k = 0; k < K; ++k) {
        provide(N);
        breed(N);
        supplyGround(N);

    }

    cout << count(N) << endl;
    return 0;

}
*/

