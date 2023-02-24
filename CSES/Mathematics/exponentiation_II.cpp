#include <bits/stdc++.h>

using namespace std;

long long custom_exp(long long a, long long b, long long modul) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 0) {
        return custom_exp((a*a) % (long long)(modul), b / 2, modul);
    } else {
        return (a * custom_exp(a, b - 1, modul)) % (long long)(modul);
    }
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin >> t;
    long long modul = 1e9+7;
    for (int i = 0; i < t; i ++) {
        long long a, b, c;
        cin >> a >> b >> c;

        long long res = custom_exp(b, c, modul - 1);
        res = custom_exp(a, res, modul);
        cout << res << "\n";
    }
    return 0;
}