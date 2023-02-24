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

    queue<int> q;
    bool visited[n + 1] = { false };
    int pret[n + 1] = { -1 };
    pret[1] = -1;
    int distance[n + 1] = { 0 };
    distance[1] = 1;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i : adj[curr]) {
            if (visited[i]) {
                continue;
            }
            q.push(i);
            visited[i] = true;
            distance[i] = distance[curr] + 1;
            pret[i] = curr;
        }
    }

    if (distance[n] == 0) {
       cout << "IMPOSSIBLE"; 
    } else {
        cout << distance[n] << "\n";
        int tmp = n;
        vector<int> vec;
        vec.push_back(tmp);
        while (pret[tmp] != -1) {
            vec.push_back(pret[tmp]);
            tmp = pret[tmp];
        }
        for (int i = vec.size() - 1; i >= 0; i --) {
            cout << vec[i] << " ";
        }
    }


    return 0;
}