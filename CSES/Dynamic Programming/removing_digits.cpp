#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    
    vector<int> dp(n + 1, 1e7);
    dp[0] = 0;
    for (int i = 1; i <= n; i ++) {
        for (char c : to_string(i)) {
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }

    cout << dp[n];
    return 0;
}