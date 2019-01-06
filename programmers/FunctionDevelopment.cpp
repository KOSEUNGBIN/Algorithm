//
// Created by 고승빈 on 2019. 1. 7..
//

#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

#define DEFAULT_PUBLISH -1
#define PROGRESS_RATE 100

using namespace std;

queue<int> makeJobQueue(vector<int> progresses, vector<int> speeds) {
    queue<int> que;
    for (int idx = 0, len = progresses.size(); idx < len; ++idx) {
        que.push((int) ceil((double) (PROGRESS_RATE - progresses[idx]) / speeds[idx]));
    }

    return que;

}

vector<int> publish(queue<int> que) {
    vector<int> jobs;
    int top = DEFAULT_PUBLISH;
    while (!que.empty()) {
        if (top < 0 || top < que.front()) {
            top = que.front();
            jobs.push_back(1);

        } else {
            ++jobs[jobs.size() - 1];

        }

        que.pop();

    }

    return jobs;

}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> que = makeJobQueue(progresses, speeds);
    return publish(que);

}

int main() {
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};
    vector<int> result = solution(progresses, speeds);
    for (int r : result) {
        cout << r << endl;

    }

    return 0;

}