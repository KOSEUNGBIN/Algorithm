//////////////////////////////////////////////////////////////////////////
// main 함수는 수정 및 접근이 불가능 합니다.

#include <iostream>
#include <cstdlib>
#include <cstdio>

#define MAX 4096
using namespace std;
static unsigned char ori_pattern[MAX][32][32];
int dummy1[MAX];
unsigned char pattern[MAX][32][32];
int dummy2[MAX];
unsigned char input[64][64];
int dummy3[MAX];

extern void init(unsigned char pattern[][32][32]);

extern int solve(unsigned char pattern[][32][32], unsigned char picture[][64]);

int main() {
    int seed;
    cin >> seed;
    srand(seed);
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < 32; j++) {
            for (int k = 0; k < 32; k++) {
                ori_pattern[i][j][k] = rand() % 256;
            }
        }
    }
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < 32; j++) {
            for (int k = 0; k < 32; k++) {
                pattern[i][j][k] = ori_pattern[i][j][k];
            }
        }
    }

    int problemNum = 4096;
    int correct = 0;
    int score = 0;

    init(pattern);

    for (int TestCase = 1; TestCase <= problemNum; TestCase++) {
        int curIdx = rand() % MAX;
        for (int i = 0; i < 64; i++) {
            for (int j = 0; j < 64; j++) {
                input[i][j] = rand() % 256;
            }
        }

        int sr = rand() % 33;
        int sc = rand() % 33;

        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                input[sr + i][sc + j] = ori_pattern[curIdx][i][j];
            }
        }
        int result = solve(pattern, input);
        if (result == curIdx) score += 1;
    }

    cout << "score : " << score;
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////

// user 영역은 수정 및 접근이 가능합니다.
// user 영역에서 init 함수 및 solve 함수를 구현하여 score 값을 최대화 하시오.

#define MAX 4096

#include <vector>
#include <map>
#include <string>

typedef long long ll;

class Node {
private:
    vector<int> num;

public:
    void add(int value) {
        num.push_back(value);

    }

    const vector<int> &getNum() const {
        return num;

    }

};

map<ll, Node> cache;

void init(unsigned char pattern[][32][32]) {
    for (int c = 0; c < MAX; ++c) {
        ll value = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                value += pattern[c][i][j];

            }

        }

        cache[value].add(c);

    }

}

int search(unsigned char pattern[][32][32], unsigned char picture[][64], int value) {
    vector<int> vec = cache[value].getNum();
    for (int v : vec) {
        for (int _startRow = 0; _startRow <= 32; ++_startRow) {
            for (int _startCol = 0; _startCol <= 32; ++_startCol) {
                bool checker = true;
                for (int i = 0; i < 32; i++) {
                    for (int j = 0; j < 32; j++) {
                        if (pattern[v][i][j] != picture[_startRow + i][_startCol + j]) {
                            checker = false;
                            break;

                        }

                    }

                    if (!checker) {
                        break;

                    }

                }

                if (checker) return v;

            }

        }

    }

    return -1;

}

int solve(unsigned char pattern[][32][32], unsigned char picture[][64]) {
    int answer = 1;
    for (int startRow = 0; startRow <= 32; ++startRow) {
        for (int startCol = 0; startCol <= 32; ++startCol) {
            long value = 0;
            for (int i = 0; i < 32; i++) {
                for (int j = 0; j < 32; j++) {
                    value += picture[i + startRow][j + startCol];

                }

            }

            answer = search(pattern, picture, value);
            if (answer >= 0) {
                return answer;

            }

        }

    }

    return answer;

}