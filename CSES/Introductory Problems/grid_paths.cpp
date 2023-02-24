#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

bool visited[7][7] = {{false}};
string s;
char mp[49];
int cnt = 0, num = 0;

void solve(int i, int j, char lt) {
    
    if (lt == 'U' && visited[i - 1][j] && j > 0 && j < 6 && !visited[i][j-1] && !visited[i][j + 1]) {
        return;
    }
    if (lt == 'D' && visited[i + 1][j] && j > 0 && j < 6 && !visited[i][j-1] && !visited[i][j + 1]) {
        return;
    }
    if (lt == 'R' && visited[i][j+1] && i > 0 && i < 6 && !visited[i-1][j] && !visited[i+1][j]) {
        return;
    }
    if (lt == 'L' && visited[i][j-1] && i > 0 && i < 6 && !visited[i-1][j] && !visited[i+1][j]) {
        return;
    }

    cnt ++;
    visited[i][j] = true;
    if (cnt == 49 && i == 6 && j == 0) {
        num ++;
        visited[i][j] = false;
        cnt --;
        return;
    }
    
    if (i == 6 && j == 0) {
        visited[i][j] = false;
        cnt --;
        return;
    }
    
    if (i - 1 >= 0 && (mp[cnt] == '?' || mp[cnt] == 'U')) {
        if (!(visited[i - 1][j] || (i - 1 == 0 && j > 0 && !visited[i - 1][j - 1]))) {
            solve(i - 1, j, 'U');
        } 
    }
    if (i + 1 < 7 && (mp[cnt] == '?' || mp[cnt] == 'D')) {
        if (!(visited[i + 1][j] || (i + 1 == 6 && j < 6 && !visited[i + 1][j + 1])))
            solve (i + 1, j, 'D');
    }
    if (j + 1 < 7 && (mp[cnt] == '?' || mp[cnt] == 'R')) {
        if (!(visited[i][j+1] || (j + 1 == 6 && i > 0 && !visited[i - 1][j + 1])))
            solve(i, j + 1, 'R');
    }
    if (j - 1 >= 0 && (mp[cnt] == '?' || mp[cnt] == 'L')) {
        if (!(visited[i][j - 1] || (j - 1 == 0 && i < 6 && !visited[i - 1][j - 1])))
            solve(i, j - 1, 'L');
    }
    visited[i][j] = false;
    cnt --;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    for (int i = 0; i < (int)s.size(); i ++) {
        mp[i + 1] = s[i];
    }
    // auto start = high_resolution_clock::now();
    solve(0, 0, 'X');
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() / 1000 << " miliseconds" << endl;
    cout << num;
    return 0;
}