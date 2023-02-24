#include <bits/stdc++.h>

using namespace std;

long long custom_exp(long long a, long long b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 0) {
        return custom_exp((a*a) % (long long)(1e9 + 7), b / 2);
    } else {
        return (a * custom_exp(a, b - 1)) % (long long)(1e9 + 7);
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i ++) {
        long long a, b;
        cin >> a >> b;

        cout << custom_exp(a, b) << "\n";
    }
    return 0;
}