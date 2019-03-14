//
// Created by 고승빈 on 2019-03-14.
//

#include <iostream>
#include <vector>

using namespace std;

class Node {
private:
    int score;
    bool visit;
    bool great;
    vector<Node *> edges;

    bool isVisit() {
        return visit;

    }

    void checkVisit() {
        visit = true;

    }

    void unCheckVisit() {
        visit = false;

    }

    void checkGreat() {
        great = true;

    }

    void unCheckGreat() {
        great = false;

    }

    int getScore() {
        return score;

    }

    bool existGreatAround() {
        for (Node *edge : edges) {
            if (edge->great) {
                return true;

            }

        }

        return false;

    }

public:
    explicit Node(int score) {
        this->score = score;
        this->visit = false;
        this->great = false;

    }

    void addEdge(Node *edge) {
        this->edges.push_back(edge);

    }

    int trace() {
        int sum = 0;
        for (Node *edge : edges) {
            sum += edge->dfs();

        }

        return sum;

    }

    int dfs() {
        if (isVisit()) { return 0; }

        checkVisit();
        int maximum = 0;
        if (!existGreatAround()) {
            checkGreat();
            maximum = getScore() + trace();
            unCheckGreat();

        }

        maximum = max(maximum, trace());
        unCheckVisit();
        return maximum;

    }

};

vector<Node *> input(int N) {
    int score;
    vector<Node *> tree(static_cast<unsigned long>(N + 1));
    for (int n = 1; n <= N; ++n) {
        cin >> score;
        Node *node = new Node(score);
        tree[n] = node;

    }

    return tree;

}

void connect(vector<Node *> &tree, int N) {
    int A, B;
    for (int n = 1; n < N; ++n) {
        cin >> A >> B;
        tree[A]->addEdge(tree[B]);
        tree[B]->addEdge(tree[A]);

    }

}

int main() {
    int N;
    cin >> N;

    vector<Node *> tree = input(N);
    connect(tree, N);
    cout << tree[1]->dfs() << "\n";
    return 0;

}