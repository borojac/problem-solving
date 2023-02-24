#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    bool processed[n + 1] = { false };
    long long distances[n + 1];
    
    const long long limit = 1e15; 

    for (int i = 1; i <= n; i ++) {
        distances[i] = limit;
    }
    distances[1] = 0;

    vector<pair<int, long long>> adj[n + 1];
    for (int i = 0; i < m; i ++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w}); 
    }

    priority_queue<pair<long long, int>> pq;
    pq.push({0, 1});
    
    while(!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();
        if (processed[curr]) continue;
        processed[curr] = true;
        for (auto t : adj[curr]) {
            if (distances[curr] + t.second < distances[t.first]) {
                distances[t.first] = distances[curr] + t.second;
                pq.push({-distances[t.first], t.first});
            }
        }
    }

    for (int i = 1; i <= n; i ++) {
        if (distances[i] == limit) {
            cout << -1 << "\n";
        } else {
            cout << distances[i] << "\n";
        }
    }






    return 0;
}