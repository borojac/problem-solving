#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> n >> m;
    vector<string> mp;

    int sx, sy, ex, ey;

    bool f1 = false, f2 = false;
    for (int i = 0; i < n; i ++) {
        string tmp;
        cin >> tmp;
        mp.push_back(tmp);
        if (!f1 || !f2) {
            for (int j = 0; j < (int)tmp.size(); j ++) {
                if (mp[i][j] == 'A') {
                    sx = i;
                    sy = j;
                    f1 = true;
                } else if (mp[i][j] == 'B') {
                    ex = i;
                    ey = j;
                    f2 = true;
                }
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> visited = vector<vector<bool>>(mp.size(), vector<bool>(mp[0].size(), false));
    // bool visited[mp.size()][mp[0].size()] = {{false}};
    char pth[mp.size()][mp[0].size()];
    // map<pair<int, int>, bool> visited;
    // map<pair<int, int>, char> pth;
    q.push({sx, sy});
    visited[sx][sy] = true;
    bool flag = false;
    while(!q.empty()) {
        pair<int, int> pt = q.front();
        q.pop();
        int x = pt.first, y = pt.second;
        if (x - 1 >= 0) {
            char t = mp[x - 1][y];
            if (t == '.' && !visited[x - 1][y]) {
                pth[x - 1][y] = 'U';
                visited[x - 1][y] = true;
                q.push({x - 1, y});
            } else if (t == 'B') {
                pth[x - 1][y] = 'U';
                flag = true;
                break;
            }
        }
        if (x + 1 < (int)mp.size()) {
            char t = mp[x + 1][y];
            if (t == '.' && !visited[x + 1][y]) {
                pth[x + 1][y] = 'D';
                visited[x + 1][y] = true;
                q.push({x + 1, y});
            } else if (t == 'B') {
                pth[x + 1][y] = 'D';
                flag = true;
                break;
            }
        }
        if (y - 1 >= 0) {
            char t = mp[x][y - 1];
            if (t == '.' && !visited[x][y - 1]) {
                pth[x][y - 1] = 'L';
                visited[x][y - 1] = true;
                q.push({x, y - 1});
            } else if (t == 'B') {
                pth[x][y - 1] = 'L';
                flag = true;
                break;
            }
        }
        if (y + 1 < (int)mp[0].size()) {
            char t = mp[x][y + 1];
            if (t == '.' && !visited[x][y + 1]) {
                pth[x][y + 1] = 'R';
                visited[x][y + 1] = true;
                q.push({x, y + 1});
            } else if (t == 'B') {
                pth[x][y + 1] = 'R';
                flag = true;
                break;
            }
        }
    }

    if (flag) {
        cout << "YES\n";
        string s = "";
        while (true) {
            char t = pth[ex][ey];
            if (t == 'R') {
                ey --;
            } else if (t == 'L') {
                ey ++;
            } else if (t == 'U') {
                ex ++;
            } else if (t == 'D') {
                ex --;
            }
            s+=t;
            if (ex == sx && ey == sy) {
                break;
            }
        }
        cout << s.size() << "\n";
        reverse(s.begin(), s.end());
        cout << s;
    } else {
        cout << "NO";
    }

    return 0;
}