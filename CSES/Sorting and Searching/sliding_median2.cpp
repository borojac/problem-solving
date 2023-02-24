#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int b = 0, e = k - 1;
    vector<int> val;
    vector<int> begs;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        val.push_back(x);
    }

    for (int i = 0; i < n - k + 1; i ++) {
        vector<int> tmp(val.begin() + i,  val.begin() +i + k);
        sort(tmp.begin(), tmp.end());

        cout << tmp[(k % 2 == 0 ? k / 2 - 1: k / 2)] << " ";
    }


    return 0;
}