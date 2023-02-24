#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<ll, ll>> pts;
    long long sx = 0, sy = 0;
    for (int i = 0; i < n; i ++) {
        ll x, y;
        cin >> x >> y;
        pts.push_back({x, y});
    }

    return 0;
}