//
// Created by 고승빈 on 2019. 1. 8..
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

class Edge {
private:
    int time;
    int next;

public:
    Edge(int next, int time) {
        this->next = next;
        this->time = time;

    }

    int getTime() const {
        return time;
    }

    int getNext() const {
        return next;
    }
};

class Vertex {
private:
    vector<Edge *> edges;

public:
    void addEdge(int next, int time) {
        Edge *edge = new Edge(next, time);
        edges.push_back(edge);

    }

    vector<Edge *> getEdges() const {
        return edges;
    }

};

class Node {
private:
    int time;
    int vertex;

public:
    Node(int vertex, int time) {
        this->vertex = vertex;
        this->time = time;
    }

    int getTime() const {
        return time;
    }

    int getVertex() const {
        return vertex;
    }

};

set<int> search(vector<Vertex> &vertex, int N) {
    queue<Node *> que;
    que.push(new Node(1, 0));
    set<int> result;
    while (!que.empty()) {
        Node *cur = que.front();
        if (cur->getVertex() == N) {
            result.insert(cur->getTime());

        } else {
            vector<Edge *> vertexs = vertex[cur->getVertex()].getEdges();
            for (Edge *edge : vertexs) {
                que.push(new Node(edge->getNext(), edge->getTime() + cur->getTime()));

            }


        }

        que.pop();

    }

    return result;

}


int main() {
    int N, M;
    int A, B, C, D;
    cin >> N >> M;
    vector<Vertex> vertexA(N + 1);
    vector<Vertex> vertexB(N + 1);

    for (int m = 0; m < M; ++m) {
        cin >> A >> B >> C >> D;
        int maxV = max(A, B);
        int minV = min(A, B);
        vertexA[minV].addEdge(maxV, C);
        vertexB[minV].addEdge(maxV, D);

    }

    set<int> sA = search(vertexA, N);
    set<int> sB = search(vertexB, N);

    for (int a : sA) {
        for (int b : sB) {
            if (a == b) {
                cout << a << "\n";
                return 0;

            }

        }

    }

    cout << "IMPOSSIBLE\n";
    return 0;

}