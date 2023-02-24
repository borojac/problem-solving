#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> grid;
    for (int i = 0; i < n; i ++) {
        string line;
        cin >> line;
        grid.push_back(line);
    }

    long long dp[n][n];
    dp[0][0] = 1;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (i != 0 || j != 0) {
                dp[i][j] = 0;
            }
            if (grid[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                if (i - 1 >= 0) {
                    dp[i][j] += dp[i - 1][j]; 
                }
                if (j - 1 >= 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
            dp[i][j] %= (long long)1e9+7;
        }
    }

    cout << dp[n - 1][n - 1];

    return 0;
}