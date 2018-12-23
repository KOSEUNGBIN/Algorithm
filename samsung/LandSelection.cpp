//
// Created by 고승빈 on 2018. 12. 22..
//

/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <string.h>
#include <queue>
#include <map>
#include <stack>

using namespace std;

int Answer;

class Node {
private:
    pair<int, int> start;
    pair<int, int> end;
public:
    Node(pair<int, int> start, pair<int, int> end) {
        this->start = start;
        this->end = end;

    }

    void setStart(const pair<int, int> &start) {
        Node::start = start;
    }

    void setEnd(const pair<int, int> &end) {
        Node::end = end;
    }

    const pair<int, int> &getStart() const {
        return start;
    }

    const pair<int, int> &getEnd() const {
        return end;
    }

    int getStartRow() {
        return start.first;
    }

    int getStartCol() {
        return start.second;
    }

    int getEndRow() {
        return end.first;
    }

    int getEndCol() {
        return end.second;
    }

    bool isInnerSpot(pair<int, int> spot) {
        return (start.first <= spot.first && spot.first <= end.first)
               && (start.second <= spot.second && spot.second <= end.second);
    }

    bool isInner(Node *node) {
        return (start.first <= node->start.first && node->end.first <= end.first)
               && (start.second <= node->start.second && node->end.second <= end.second);
    }

    bool isOutter(Node *node) {
        return (node->start.first <= start.first && end.first <= node->end.first)
               && (node->start.second <= start.second && end.second <= node->end.second);
    }

};

char **insert(int N) {
    string input;
    char **roadMap = new char *[N];
    for (int row = 0; row < N; ++row) {
        cin >> input;
        roadMap[row] = new char[N];
        const char *strC = input.c_str();
        for (int idx = 0, len = strlen(strC); idx < len; ++idx) {
            roadMap[row][idx] = strC[idx];

        }

    }

    return roadMap;

}

bool isDuplicated(queue<Node *> *interval, Node *node) {
    bool isInner = false;
    bool isOutter = false;
    stack<Node *> temp;
    while (!interval->empty()) {
        Node *in = interval->front();
        if (in->isInner(node)) {
            temp.push(in);
            isInner = true;

        } else if (in->isOutter(node)) {
            isOutter = true;

        } else {
            temp.push(in);

        }

        interval->pop();

    }

    while (!temp.empty()) {
        Node *t = temp.top();
        interval->push(t);
        temp.pop();

    }

    if (isOutter) {
        interval->push(node);

    }

    return isInner || isOutter;

}

int dfs(char **roadMap, Node *node, bool **cache, char ch, pair<int, int> spot) {
    if (!node->isInnerSpot(spot)) {
        return 0;

    }

    if (roadMap[spot.first][spot.second] != ch) {
        return 0;

    }

    if (cache[spot.first][spot.second]) {
        return 0;

    }

    cache[spot.first][spot.second] = true;
    int result = 1;
    result += dfs(roadMap, node, cache, ch, make_pair(spot.first + 1, spot.second));
    result += dfs(roadMap, node, cache, ch, make_pair(spot.first - 1, spot.second));
    result += dfs(roadMap, node, cache, ch, make_pair(spot.first, spot.second + 1));
    result += dfs(roadMap, node, cache, ch, make_pair(spot.first, spot.second - 1));
    return result;

}

bool check(char **roadMap, Node *node) {
    bool **cache = new bool *[20];
    for (int idx = 0; idx < 20; ++idx) {
        cache[idx] = new bool[20]{false,};

    }

    map<char, int> store;
    for (int row = node->getStartRow(); row <= node->getEndRow(); row++) {
        for (int col = node->getStartCol(); col <= node->getEndCol(); col++) {
            int result = dfs(roadMap, node, cache, roadMap[row][col], make_pair(row, col));
            if (result >= 1) {
                store[roadMap[row][col]]++;

            }

        }

    }

    bool isTwo = store.size() == 2;
    bool isExistOne = false;
    bool isExistTwo = false;
    for (auto it = store.begin(); it != store.end(); it++) {
        if (it->second == 1) {
            isExistOne = true;

        } else if (it->second >= 2) {
            isExistTwo = true;

        }

    }

    return isTwo && isExistOne && isExistTwo;

}

int loop(char **roadMap, int N) {
    queue<Node *> interval;
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            // middle
            for (int endRow = row; endRow < N; ++endRow) {
                for (int endCol = col; endCol < N; ++endCol) {
                    Node *node = new Node(make_pair(row, col), make_pair(endRow, endCol));
                    if (check(roadMap, node) && !isDuplicated(&interval, node)) {
                        interval.push(node);

                    }

                }

            }

        }

    }

    return interval.size();

}

int main(int argc, char **argv) {
    int T, test_case;
    /*
       The freopen function below opens input.txt file in read only mode, and afterward,
       the program will read from input.txt file instead of standard(keyboard) input.
       To test your program, you may save input data in input.txt file,
       and use freopen function to read from the file when using cin function.
       You may remove the comment symbols(//) in the below statement and use it.
       Use #include<cstdio> or #include <stdio.h> to use the function in your program.
       But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */

    // freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {

        /////////////////////////////////////////////////////////////////////////////////////////////
        int N;
        cin >> N;
        char **roadMap = insert(N);
        Answer = loop(roadMap, N);

        /////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}