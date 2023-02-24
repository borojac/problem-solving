#include <bits/stdc++.h>

using namespace std;

bool tmpC(pair<int, int> a, pair<int, int> b) {
    double d1 = (double)a.first / a.second;
    double d2 = (double)b.first / b.second;
    return d1 < d2;
}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    pair<int, int> arr[n];
    for (int i = 0; i < n; i ++) {
        cin >> arr[i].first;
    }
    for (int i = 0; i < n; i ++) {
        cin >> arr[i].second;
    }

    sort(arr, arr + n, tmpC);

    long long cntPages = 0;
    for (int i = 0; i < n; i ++) {
        if (x > arr[i].first) {
            cntPages += arr[i].second;
            x -= arr[i].first;
        }
    }
    cout << cntPages;
    return 0;
}