#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll summ = 0;
    for (int i = 0; i < n - 1; i ++) {
        int tmp;
        cin >> tmp;
        summ += tmp;
    }

    cout << n * (n + 1) / 2 - summ << "\n";

    return 0;
}