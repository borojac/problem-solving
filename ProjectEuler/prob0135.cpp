#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
// a+b a a-b
int main() {
    ll n = 1000000;
    map<ll, ll> mp;
    for (ll a = 1; a < n; a++) {
        // if (a % 1000 == 0) cout << a << endl;
        for (ll b = ceil(a / 4); b < a; b++) {
            if (a * (4 * b - a) > n) break;
            mp[a * (4 * b - a)]++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (mp[i] == 10) cnt++;
    }

    cout << cnt << endl;
}
