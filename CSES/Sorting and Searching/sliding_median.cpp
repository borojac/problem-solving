#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);

    int n, k;
    cin >> n >> k;

    int b = 0, e = k - 1;
    vector<int> val;
    vector<int> begs;
    for (int i = 0; i < k; i ++) {
        int x;
        cin >> x;
        val.push_back(x);
        begs.push_back(x);
    }

    bool even = k % 2 == 0;
    sort(val.begin(), val.end());

    cout << val[(even ? val.size() / 2 - 1 : val.size() / 2)] << " ";

    for (int i = k; i < n; i ++) {
        int x;
        cin >> x;
        begs.push_back(x);
        val.erase(find(val.begin(), val.end(), begs[b++]));
        val.insert(lower_bound(val.begin(), val.end(), x), x);
        cout << val[(even ? val.size() / 2 - 1 : val.size() / 2)] << " ";
    }


    return 0;
}