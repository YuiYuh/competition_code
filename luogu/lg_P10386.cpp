#include<bits/stdc++.h>
using namespace std;

int lines[12][5] = {
    // 行
    {0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}, {10, 11, 12, 13, 14}, {15, 16, 17, 18, 19}, {20, 21, 22, 23, 24},
    // 列
    {0, 5, 10, 15, 20}, {1, 6, 11, 16, 21}, {2, 7, 12, 17, 22}, {3, 8, 13, 18, 23}, {4, 9, 14, 19, 24},
    // 对角线
    {0, 6, 12, 18, 24}, {4, 8, 12, 16, 20}
};


bool is_draw(const vector<int>& board) {
    for (int i = 0; i < 12; ++i) {
        int color = board[lines[i][0]];
        bool all_same = true;
        for (int j = 1; j < 5; ++j) {
            if (board[lines[i][j]] != color) {
                all_same = false;
                break;
            }
        }
        if (all_same) return false;
    }
    return true;
}

int main() {
    vector<int> board(25);
    for (int i = 0; i < 12; ++i) board[i] = 0;
    for (int i = 12; i < 25; ++i) board[i] = 1;

    long long count = 0;

    do {
        if (is_draw(board)) {
            count++;
        }
    } while (next_permutation(board.begin(), board.end()));

    cout << count << endl;

    return 0;
}

