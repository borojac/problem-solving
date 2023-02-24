#include <bits/stdc++.h>

using namespace std;

void solveRoom(vector<string>& mp, int i, int j) {
    mp[i][j] = '#';
    if (i + 1 < mp.size() && mp[i+1][j] == '.') {
        solveRoom(mp, i + 1, j);
    }
    if (i - 1 >= 0 && mp[i - 1][j] == '.') {
        solveRoom(mp, i - 1, j);
    }
    if (j + 1 < mp[0].size() && mp[i][j + 1] == '.') {
        solveRoom(mp, i, j + 1);
    }
    if (j - 1 >= 0 && mp[i][j - 1] == '.') {
        solveRoom(mp, i, j - 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> n >> m;
    vector<string> mp;

    for (int i = 0; i < n; i ++) {
        string tmp;
        cin >> tmp;
        mp.push_back(tmp);
    }

    int cnt = 0;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (mp[i][j] == '.') {
                solveRoom(mp, i, j);
                cnt ++;
            }
        }
    }

    cout << cnt;

    return 0;
}