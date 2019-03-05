//
// Created by 고승빈 on 2019. 3. 5..
//

#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define LIMIT 51
using namespace std;

class Node {
private:
    string word;
    int count;

public:
    Node(string word, int count) {
        this->word = word;
        this->count = count;

    }

    string getWord() {
        return word;

    }

    int getCount() {
        return count;

    }

};

bool isOnlyDiffrence(string mine, string compare) {
    if (mine.length() != compare.length()) {
        return false;

    }

    int count = 0;
    for (int idx = 0, len = mine.length(); idx < len; ++idx) {
        if (mine.at(idx) != compare[idx]) {
            count++;

        }

        if (count > 1) {
            return false;

        }

    }

    return count == 1;

}

int bfs(string begin, string target, vector<string> words) {
    queue<Node *> que;
    que.push(new Node(begin, 0));
    vector<bool> visits(words.size(), false);
    int minimum = LIMIT;
    while (!que.empty()) {
        Node *node = que.front();
        for (int idx = 0; idx < words.size(); ++idx) {
            if (visits[idx]) {
                continue;

            }

            if (isOnlyDiffrence(node->getWord(), words[idx])) {
                visits[idx] = true;
                if (target.compare(words[idx]) == 0) {
                    minimum = min(minimum, node->getCount() + 1);

                } else {
                    que.push(new Node(words[idx], node->getCount() + 1));

                }

            }

        }

        que.pop();

    }

    return minimum >= LIMIT ? 0 : minimum;

}

int solution(string begin, string target, vector<string> words) {
    return bfs(begin, target, words);

}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words
//            = { "hot", "dot", "dog", "lot", "log", "cog"};
            = {"hot", "dot", "dog", "lot", "log"};
    cout << solution(begin, target, words) << endl;
    return 0;

}