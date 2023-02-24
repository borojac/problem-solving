#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> points;
    vector<pair<long long, long long>> queries;

    for (int i = 0; i < n; i ++) {
        long long x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    for (int i = 0; i < m; i ++) {
        long long x, y;
        cin >> x >> y;
        queries.push_back({x, y});
    }

    long long area = 0;

    for (int i = 0; i < n; i ++) {
        if (i < n - 1) {
            area -= points[i].second*points[i + 1].first;
            area += points[i].first*points[i + 1].second;
        } else {
            area += points[i].first*points[0].second;
            area -= points[i].second*points[0].first;
        }
    }

    

    return 0;
}