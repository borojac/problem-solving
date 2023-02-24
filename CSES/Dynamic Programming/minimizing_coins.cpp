#include <bits/stdc++.h>

using namespace std;

long long solve(vector<long long>& coins, int x, vector<bool>& check, vector<long long>& vals) {
    if (x < 0) {
        return INT_MAX;
    }
    if (x == 0) {
        return 0;
    }
    if (check[x]) {
        return vals[x];
    }

    long long minn = INT_MAX;
    for (int i = 0; i < (int)coins.size(); i ++) {
        minn = min(solve(coins, x - coins[i], check, vals) + 1, minn);
    }

    check[x] = true;
    vals[x] = minn;
    return minn;
}

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> coins;
    vector<bool> check = vector<bool>(x + 1, false);
    vector<long long> vals = vector<long long>(x + 1);

    for (int i = 0; i < n; i ++) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    long long res = solve(coins, x, check, vals);
    cout << ((res == INT_MAX) ? -1 : res);

    return 0;
}