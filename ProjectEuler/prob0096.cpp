#include <bits/stdc++.h>

using namespace std;

bool checkRowCol(vector<vector<int>> &s, int ii, int jj) {
    for (int i = 0; i < 9; i++) {
        if (s[ii][i] == s[ii][jj] && jj != i)
            return false;
        if (s[i][jj] == s[ii][jj] && ii != i)
            return false;
    }

    int kvX = jj / 3;
    int kvY = ii / 3;
    for (int i = kvY * 3; i < kvY * 3 + 3; i++) {
        for (int j = kvX * 3; j < kvX * 3 + 3; j++) {
            if (s[i][j] == s[ii][jj] && !(ii == i && j == jj))
                return false;
        }
    }

    return true;
}

bool checkCompletion(vector<vector<int>> &s) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (s[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool solved = false;
int summ = 0;
void solve(vector<vector<int>> &s, int ii, int jj) {
    if (solved)
        return;
    if (checkCompletion(s)) {
        summ += 100 * s[0][0] + 10 * s[0][1] + s[0][2];
        solved = true;
        return;
    }
    if (ii == -1)
        return;

    for (int k = 1; k <= 9; k++) {
        s[ii][jj] = k;
        if (solved)
            return;
        bool c = checkRowCol(s, ii, jj);
        if (!c) {
            s[ii][jj] = 0;
            continue;
        }
        int nexti = -1, nextj = -1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (s[i][j] == 0) {
                    // solve(s, i, j);
                    nexti = i;
                    nextj = j;
                    i = 9;
                    break;
                    // break tt;
                }
            }
        }
        solve(s, nexti, nextj);
        s[ii][jj] = 0;
        if (solved)
            return;
    }
}

void printt(vector<vector<int>> s) {
    for (int i = 0; i < 9; i++) {
        cout << endl;
        for (int j = 0; j < 9; j++) {
            cout << s[i][j] << " ";
        }
    }
}

int main() {
    freopen("sudoku.txt", "r", stdin);

    vector<vector<vector<int>>> ss;

    for (int i = 0; i < 50; i++) {
        string x;
        cin >> x;
        cin >> x;
        vector<vector<int>> tmpS;
        for (int j = 0; j < 9; j++) {
            cin >> x;
            vector<int> tmp;
            for (int k = 0; k < 9; k++) {
                tmp.push_back(x[k] - '0');
            }
            tmpS.push_back(tmp);
        }
        ss.push_back(tmpS);
    }

    for (int t = 0; t < 50; t++) {
        // printt(ss[t]);
        solved = false;
        int nexti = 0, nextj = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (ss[t][i][j] == 0) {
                    // solve(s, i, j);
                    nexti = i;
                    nextj = j;
                    i = 9;
                    break;
                    // break tt;
                }
            }
        }
        solve(ss[t], nexti, nextj);
        cout << t + 1 << " -> Finished. Sum= " << summ << " ... Solved status: " << solved << endl;
    }
    cout << summ << endl;

    return 0;
}