#include <bits/stdc++.h>

using namespace std;

void dfs(int x, vector<int> adj[], vector<bool>& visited, bool& flag, int pret, int pret2) {
    if (!flag) return;
    for (int ii : adj[x]) {
        if (pret2 != -1 && visited[ii] && ii == pret2) {
            flag = false;
            return;
        }

        if (visited[ii]) continue;
        visited[ii] = true;
        dfs(ii, adj, visited, flag, x, pret);
    }
}

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
    bool isPossible = true;
    for (int i = 1; i <= n; i ++) {
        if (!visited[i]) {
            dfs(1, adj, visited, isPossible, -1, -1);
            if (!isPossible) break;
        }
    }
    if (isPossible) {
        map<int, int> mp;
        visited = vector<bool>(n + 1, false);
        for (int i = 1; i <= n; i ++) {
            if (!visited[i]) {
                mp[i] = 1;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    for (int ii : adj[curr]) {
                        if (visited[ii]) continue;
                        mp[ii] = (mp[curr] == 1) ? 2 : 1;
                        visited[ii] = true;
                        q.push(ii);
                    }
                }
            }
        }
        for (int i = 1; i<= n;i  ++) {
            cout << mp[i] << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}