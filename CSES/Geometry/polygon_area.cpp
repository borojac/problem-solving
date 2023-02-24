#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<long long, long long>> points;

    for (int i = 0; i < n; i ++) {
        long long x, y;
        cin >> x >> y;
        points.push_back({x, y});
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

    cout << abs(area);

    return 0;
}