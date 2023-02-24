#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    long long mod = 1e9 + 7;
    cin >> n;
    long long summ = 1;
    for (int i = 0; i < n; i ++) {
        summ *= 2;
        summ %= mod;
    }

    cout << summ << "\n";

    return 0;
}