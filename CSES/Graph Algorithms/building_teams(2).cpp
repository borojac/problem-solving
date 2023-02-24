#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n + 1, false);
    int team[n + 1] = { 0 };
    visited = vector<bool>(n + 1, false);
    bool isPossible = true;
    for (int i = 1; i <= n; i ++) {
        if (!visited[i]) {
            bool f = true;
            team[i] = 1;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int ii : adj[curr]) {
                    if (visited[ii] && team[ii] == team[curr]) {
                        cout << ii << " " << curr << endl;
                        isPossible = false;
                        break;
                    }
                    if (visited[ii]) continue;
                    team[ii] = f ? 2 : 1;
                    visited[ii] = true;
                    q.push(ii);
                }
                if (!isPossible) break;
                f = !f;
            }
        }
    }
    if (!isPossible) {
        cout << "IMPOSSIBLE";
    } else {
        for (int i = 1; i<= n;i  ++) {
            cout << team[i] << " ";
        }
    }
    return 0;
}