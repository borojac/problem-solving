#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a, b;
    for (int i = 0; i < n; i ++) {
        int x;cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < k; i ++) {
        int x; cin >> x;
        b.push_back(x);
    }

    int maxx = *max_element(a.begin(), a.end());
    bool f = false;
    for (int i = 0; i < k; i ++) {

        if (maxx == a[b[i]-1]) f= true;
    }

    if (f) cout <<"Yes";
    else cout << "No";
    return 0;
}