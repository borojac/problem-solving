#include <bits/stdc++.h>

using namespace std;

bool isFree(vector<vector<bool>>& board, vector<vector<bool>>& traps, int ii, int jj) {
    if (traps[ii][jj])
        return false;
    for (int i = 0; i <= ii; i ++) {
        for (int j = 0; j < 8; j ++) {
            if (board[i][j]) {
                if (i + j == ii + jj || i - j == ii - jj || i == ii || j == jj) {
                    return false;
                }
            }
        }
    }
    return true;
}

void solve(vector<vector<bool>>& board, int& cnt, int queens, vector<vector<bool>>& traps) {
    if (queens == 8) {
        cnt ++;
        return;
    } else {
        for (int i = 0; i < 8; i ++) {
            if (isFree(board, traps, queens, i)) {
                board[queens][i] = true;
                solve(board, cnt, queens + 1, traps);
                board[queens][i] = false;
            }
        }
    }
}

int main() {

    vector<vector<bool>> board = vector<vector<bool>>(8, vector<bool>(8, false));
    vector<vector<bool>> traps = vector<vector<bool>>(8, vector<bool>(8, false));
    int cnt = 0;
    int queens = 0;

    for (int i = 0; i < 8; i ++) {
        string line;
        cin >> line;
        for (int j = 0; j < 8; j ++) {
            if (line[j] == '*') {
                traps[i][j] = true;
            }
        }
    }
    solve(board, cnt, queens, traps);
    cout << cnt << "\n";

    return 0;
}