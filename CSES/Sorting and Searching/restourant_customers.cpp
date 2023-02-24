#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> movies;

    for (int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        movies.push_back({a, b});
    }

    sort(movies.begin(), movies.end(), [](auto a, auto b) { return a.second == b.second ? a.first < b.first : a.second < b.second;});

    int cnt = 0;
    int last = -1;
    for (int i = 0; i < n; i ++) {
        if (i == 0) {
            cnt ++;
            last = movies[i].second;
            continue;
        }
        if (movies[i].first >= last) {
            cnt ++;
            last = movies[i].second;
            continue;
        }
    }

    cout << cnt;

    return 0;
}