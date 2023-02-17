#include <bits/stdc++.h>

using namespace std;

bool cmp(tuple<int, int> a, tuple< int, int> b) {
    return get<1>(a) < get<1>(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);

    vector<tuple<int, int>> vec;
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        vec.push_back(make_tuple(i, x));
    }

    sort(vec.begin(), vec.end(), cmp);

    long long summ =0;

    for (int i = 0; i < n - 1; i ++) {
        summ += abs(get<0>(vec[i]) - get<0>(vec[i + 1]));
    }

    cout << summ;

    return 0;
}