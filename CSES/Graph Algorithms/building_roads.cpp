#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int  i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool visited[n + 1] = { false };
    int cnt = 0;
    vector<int> conn;
    for (int i = 1; i <= n; i ++) {
        if (!visited[i]) {
            conn.push_back(i);
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int ii : adj[curr]) {
                    if (visited[ii]) continue;
                    q.push(ii);
                    visited[ii] = true;
                }
            }
            cnt ++;
        }
    }

    cout << cnt - 1 << "\n";
    for (int i = 0; i < conn.size() - 1; i ++) {
        cout << conn[i] << " " << conn[i + 1] << "\n";
    }

    return 0;
}