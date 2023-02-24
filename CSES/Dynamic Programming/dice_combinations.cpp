#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long dp[n + 1] = { 0 };
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i ++) {
        dp[i] += dp[i - 1];
        if (i - 2 >= 0)
            dp[i] += dp[i - 2];
        if (i - 3 >= 0)
            dp[i] += dp[i - 3];
        if (i - 4 >= 0)
            dp[i] += dp[i - 4];
        if (i - 5 >= 0)
            dp[i] += dp[i - 5];
        if (i - 6 >= 0)
            dp[i] += dp[i - 6];
        dp[i] %= (long long)1e9 + 7;
    }

    cout << dp[n];
    return 0;
}