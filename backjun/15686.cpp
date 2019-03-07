//
// Created by 고승빈 on 2019-03-07.
//

#include <iostream>
#include <vector>

#define MAX_VALUE 100000000
#define MAX_DISTANCE 1000

using namespace std;

class House {
private:
    int y;
    int x;

public:
    House(int y, int x) {
        this->y = y;
        this->x = x;

    }

    int getY() {
        return y;

    }

    int getX() {
        return x;

    }

};

class ChickenStore {
private:
    int y;
    int x;
    bool visit;

public:
    ChickenStore(int y, int x) {
        this->y = y;
        this->x = x;
        this->visit = false;

    }

    bool isSelected() {
        return visit;

    }

    bool isNotSelected() {
        return !isSelected();

    }

    void markVisit() {
        visit = true;

    }

    void markUnVisit() {
        visit = false;

    }

    int getY() {
        return y;

    }

    int getX() {
        return x;

    }

};

int distance(ChickenStore *chickenStore, House *house) {
    return abs(chickenStore->getX() - house->getX()) + abs(chickenStore->getY() - house->getY());

}

int measure(vector<ChickenStore *> &chickenStores, vector<House *> &houses) {
    int distances = 0;
    for (House *house : houses) {
        int minimum = MAX_DISTANCE;
        for (ChickenStore *chickenStore : chickenStores) {
            if (chickenStore->isSelected()) {
                minimum = min(minimum, distance(chickenStore, house));

            }

        }

        distances += minimum;

    }

    return distances;

}

int trace(vector<ChickenStore *> &chickenStores, vector<House *> &houses, int begin, int selectedCount,
          int selectedMaxCount) {
    if (selectedCount >= selectedMaxCount || begin >= chickenStores.size()) { // 종료 조건
        return measure(chickenStores, houses);

    }

    int minimum = MAX_VALUE;
    for (int idx = begin; idx < chickenStores.size(); ++idx) {
        if (chickenStores[idx]->isNotSelected()) {
            chickenStores[idx]->markVisit();
            minimum = min(minimum, trace(chickenStores, houses, idx + 1, selectedCount + 1, selectedMaxCount));
            chickenStores[idx]->markUnVisit();

        }

    }

    return minimum;

}

int main() {
    int N, M;
    cin >> N >> M;

    vector<House *> houses;
    vector<ChickenStore *> chickenStores;
    int input;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> input;
            if (input == 1) {
                houses.push_back(new House(y, x));

            } else if (input == 2) {
                chickenStores.push_back(new ChickenStore(y, x));

            }

        }

    }

    printf("%d\n", trace(chickenStores, houses, 0, 0, M));
    return 0;

}