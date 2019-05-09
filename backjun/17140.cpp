//
// Created by 고승빈 on 2019-05-08.
//

#include <iostream>
#include <vector>

#define MAX_LENGTH 101
#define MAX_SORT_LENGTH 101
#define LIMIT_TIME 100
#define MAX_NUMBER 101

using namespace std;

int matrix[MAX_LENGTH][MAX_LENGTH][MAX_LENGTH];

bool isOver(int time) {
    return time >= LIMIT_TIME;

}

bool isSuitable(int time, int r, int c, int k) {
    return matrix[time][r][c] == k;

}

int minCounter(int counter[MAX_SORT_LENGTH]) {
    int min = MAX_NUMBER;
    for (int c = 1; c < MAX_SORT_LENGTH; ++c) {
        if (0 < counter[c] && counter[c] < min) {
            min = counter[c];

        }

    }

    return min == MAX_NUMBER ? 0 : min;

}

int findMinimumNumber(int counter[MAX_SORT_LENGTH], int count) {
    for (int c = 1; c < MAX_SORT_LENGTH; ++c) {
        if (counter[c] == count) {
            counter[c] = 0;
            return c;

        }

    }

    return -1;  // error

}

int arrangeRow(int time, int row, int columnCount) {
    int counter[MAX_SORT_LENGTH] = {0,};
    for (int column = 1; column <= columnCount; ++column) {
        ++counter[matrix[time][row][column]];

    }

    int nextTime = time + 1;
    int nextColumnCount = 0;
    int count;
    while ((count = minCounter(counter)) > 0) {
        int minimumNumber = findMinimumNumber(counter, count);
        matrix[nextTime][row][++nextColumnCount] = minimumNumber;
        matrix[nextTime][row][++nextColumnCount] = count;
        if (nextColumnCount >= 100) break;

    }

    return nextColumnCount;

}

int arrangeColumn(int time, int column, int rowCount) {
    int counter[MAX_SORT_LENGTH] = {0,};
    for (int row = 1; row <= rowCount; ++row) {
        ++counter[matrix[time][row][column]];

    }

    int nextTime = time + 1;
    int nextRowCount = 0;
    int count;
    while ((count = minCounter(counter)) > 0) {
        int minimumNumber = findMinimumNumber(counter, count);
        matrix[nextTime][++nextRowCount][column] = minimumNumber;
        matrix[nextTime][++nextRowCount][column] = count;
        if (nextRowCount >= 100) break;

    }

    return nextRowCount;

}

void display(int time, int rowCount, int columnCount) {
    cout << "time ) " << time << endl;
    for (int row = 1; row <= rowCount; ++row) {
        for (int column = 1; column <= columnCount; ++column) {
            cout << matrix[time][row][column] << " ";

        }

        cout << endl;

    }

    cout << endl;

}

int operateR(int time, int rowCount, int columnCount) {
    int maxColumnCount = columnCount;
    for (int row = 1; row <= rowCount; ++row) {
        int ret = arrangeRow(time, row, columnCount);
        if (maxColumnCount < ret) {
            maxColumnCount = ret;

        }

    }

//    display(time + 1, rowCount, maxColumnCount);
    return maxColumnCount;

}

int operateC(int time, int rowCount, int columnCount) {
    int maxRowCount = rowCount;
    for (int column = 1; column <= columnCount; ++column) {
        int ret = arrangeColumn(time, column, rowCount);
        if (maxRowCount < ret) {
            maxRowCount = ret;

        }

    }

//    display(time + 1, maxRowCount, columnCount);
    return maxRowCount;

}

int solve(int r, int c, int k) {
    int time = 0;
    int rowCount = 3;
    int columnCount = 3;
    while (!isSuitable(time, r, c, k)) {
        // check
        if (isOver(time)) { return -1; }

        // operate
        if (rowCount >= columnCount) { columnCount = operateR(time, rowCount, columnCount); }
        else { rowCount = operateC(time, rowCount, columnCount); }

        ++time;

    }

    return time;

}

int main() {
    int r, c, k;
    cin >> r >> c >> k;

    // input
    for (int y = 1; y <= 3; ++y) {
        for (int x = 1; x <= 3; ++x) {
            cin >> matrix[0][y][x];

        }

    }

    // print
    cout << solve(r, c, k) << endl;
    return 0;

}