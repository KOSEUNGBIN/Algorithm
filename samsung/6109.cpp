//
// Created by 고승빈 on 2018. 12. 13..
//

/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>

#define UP "up"
#define DOWN "down"
#define LEFT "left"
#define RIGHT "right"

using namespace std;

int row_mover[4] = {-1, 1, 0, 0};
int col_mover[4] = {0, 0, -1, 1};

class Node {
private:
    int value;
    bool merged;

public:
    Node() {
        this->value = 0;
        merged = false;

    }

    void setValue(int value) {
        this->value = value;

    }

    void addValue(int value) {
        this->value += value;

    }

    int getValue() {
        return value;

    }

    bool isZero() {
        return value == 0;

    }

    bool equals(Node n) {
        return this->value == n.value;

    }

    bool isMerged() {
        return merged;

    }

    void setMerged(bool merged) {
        this->merged = merged;

    }

};

void move(Node **board, int r, int c, int rowVal, int colVal) {
    if (board[r + rowVal][c + colVal].isZero() && !board[r][c].isZero()) {
        board[r + rowVal][c + colVal].setValue(board[r][c].getValue());
        board[r + rowVal][c + colVal].setMerged(board[r][c].isMerged());
        board[r][c].setValue(0);
        board[r][c].setMerged(false);

    } else if (board[r][c].equals(board[r + rowVal][c + colVal]) &&
               !board[r + rowVal][c + colVal].isMerged() && !board[r][c].isMerged()) {
        board[r + rowVal][c + colVal].addValue(board[r][c].getValue());
        board[r + rowVal][c + colVal].setMerged(true);
        board[r][c].setValue(0);

    }

}

void checkUp(Node **board, int N, string direction) {
    if (direction != UP) return;
    int rowVal = row_mover[0];
    int colVal = col_mover[0];
    for (int c = 0; c < N; c++) {
        for (int r = 0; r < N; r++) {
            if (board[r][c].isZero()) {
                continue;

            }

            for (int m = r; m > 0; m--) {
                move(board, m, c, rowVal, colVal);

            }

        }

    }

}

void checkDown(Node **board, int N, string direction) {
    if (direction != DOWN) return;
    int rowVal = row_mover[1];
    int colVal = col_mover[1];
    for (int c = 0; c < N; c++) {
        for (int r = N - 1; r >= 0; r--) {
            if (board[r][c].isZero()) {
                continue;

            }

            for (int m = r; m < N - 1; m++) {
                move(board, m, c, rowVal, colVal);

            }

        }

    }

}

void checkLeft(Node **board, int N, string direction) {
    if (direction != LEFT) return;
    int rowVal = row_mover[2];
    int colVal = col_mover[2];
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (board[r][c].isZero()) {
                continue;

            }

            for (int m = c; m > 0; m--) {
                move(board, r, m, rowVal, colVal);

            }

        }

    }

}

void checkRight(Node **board, int N, string direction) {
    if (direction != RIGHT) return;
    int rowVal = row_mover[3];
    int colVal = col_mover[3];
    for (int r = 0; r < N; r++) {
        for (int c = N - 1; c >= 0; c--) {
            if (board[r][c].isZero()) {
                continue;

            }

            for (int m = c; m < N - 1; m++) {
                move(board, r, m, rowVal, colVal);

            }

        }

    }

}

void play(int N, Node **board, string direction) {
    checkUp(board, N, direction);
    checkDown(board, N, direction);
    checkLeft(board, N, direction);
    checkRight(board, N, direction);

}

int main(int argc, char **argv) {
    int test_case;
    int T;
    /*
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
    //freopen("input.txt", "r", stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case) {

        /////////////////////////////////////////////////////////////////////////////////////////////
        int N;
        string direction;
        cin >> N >> direction;
        Node **board = new Node *[N];
        for (int r = 0; r < N; r++) {
            board[r] = new Node[N];
            for (int c = 0; c < N; c++) {
                int input;
                cin >> input;
                board[r][c].setValue(input);

            }

        }

        play(N, board, direction);
        cout << "#" << test_case << "\n";
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                cout << board[r][c].getValue() << " ";

            }

            cout << "\n";

        }
        /////////////////////////////////////////////////////////////////////////////////////////////


    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.

}
