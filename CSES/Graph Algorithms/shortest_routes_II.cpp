#include <bits/stdc++.h>

#define inf 500*1e10
#define limit 500

#define forn(it,n) for (int it = 1; it <= n; it ++)

using namespace std;

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;

    long long graph[limit + 1][limit + 1];
    for (int i = 0; i <= limit; i ++) {
        for (int j = 0; j <= limit; j ++) {
            graph[i][j] = inf;
            if (i == j) {
                graph[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i ++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        if (graph[a][b] < w) continue;
        graph[a][b] = w;
        graph[b][a] = w;
    }

    forn(k,n) {
        forn(i,n) {
            forn(j, n) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (int i = 0; i < q; i ++) {
        int a, b;
        cin >> a >> b;
        if (graph[a][b] == inf) {
            cout << -1 << "\n";
        } else {
            cout << graph[a][b] << "\n";
        }
    }

    return 0;
}