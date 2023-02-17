#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);

    long long m,n,a;
    cin >> n >> m >> a;
    if (a > n && a > m) {
        cout << 1;
    } else if (a > n) {
        cout << ceil( (double)m / a);
    } else if (a > m) {
        cout << ceil((double)n / a);
    } else {
        cout << (long long)(ceil((double)n / a) * ceil((double)m / a));
    }

    return 0;
}