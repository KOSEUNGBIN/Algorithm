//
// Created by 고승빈 on 2019-04-09.
//

#include <string>
#include <vector>
#include <set>
#include <utility>
#include <iostream>

using namespace std;

int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

int solution(vector<int> arrows) {
    set<pair<int, int>> vertexList;
    set<pair<pair<int, int>, pair<int, int>>> edgeList;
    int y = 0;
    int x = 0;
    vertexList.insert(make_pair(y, x));
    for (int arrow : arrows) {
        for (int c = 0; c < 2; ++c) {
            int nextY = y + dy[arrow];
            int nextX = x + dx[arrow];

            vertexList.insert(make_pair(nextY, nextX));

            pair<int, int> prevVertex = make_pair(y, x);
            pair<int, int> nextVertex = make_pair(nextY, nextX);
            if (prevVertex > nextVertex) {
                swap(prevVertex, nextVertex);

            }

            edgeList.insert(make_pair(prevVertex, nextVertex));
            y = nextY;
            x = nextX;

        }

    }

    return edgeList.size() - vertexList.size() + 1;

}

int main() {
    vector<int> arr =
//            {6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0};
//            {0, 4 , 1};
//            {1, 4, 6, 6, 0 , 3};
//            {6, 0, 2, 4, 2, 0, 6, 4};
//            {1, 4, 6, 1, 4, 6, 1, 4, 6, 1, 4, 6, 2, 0, 6, 4};
//            {0, 2, 5, 2, 7, 2};
//            {2, 7, 2, 5, 0};
//            {1, 1, 4, 4, 6, 6, 1, 7, 3};
            {0, 3, 0, 6, 4, 1, 4, 6};
    cout << solution(arr) << endl;
    return 0;

}