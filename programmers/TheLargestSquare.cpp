//
// Created by 고승빈 on 2019-03-06.
//

#include <iostream>
#include<vector>

using namespace std;

int maxSquare(vector<vector<int>> board) {
    int maximum = 0;
    for (vector<int> vec : board) {
        for (int value : vec) {
            maximum = max(maximum, value);

        }

    }

    return maximum;

}

int solution(vector<vector<int>> board) {
    int height = board.size();
    int width = board[0].size();
    if (min(height, width) == 1) {
        return board[0][0];

    }

    for (int row = 1; row < height; ++row) {
        for (int col = 1; col < width; ++col) {
            if (board[row - 1][col] > 0 && board[row][col - 1] > 0 && board[row - 1][col - 1] > 0 &&
                board[row][col] > 0) {
                board[row][col] = min(board[row - 1][col - 1], min(board[row - 1][col], board[row][col - 1])) + 1;

            }

        }

    }

    int maxLen = maxSquare(board);
    return maxLen * maxLen;

}