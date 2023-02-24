#include <bits/stdc++.h>

using namespace std;

long long solve(int x, vector<long long>& coins, vector<bool>& check, vector<long long>& vals) {
    if (x == 0) {
        return 1;
    }
    if (x < 0) {
        return 0;
    }
    if (check[x]) {
        return vals[x];
    }
    long long summ = 0;
    for (int i = 0; i < (int) coins.size(); i ++) {
        summ += solve(x - coins[i], coins, check, vals);
        summ %= (long long)1e9+7;
    }

    check[x] = true;
    vals[x] = summ;

    return summ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long x;
    cin >> n >> x;
    vector<long long> coins;
    vector<bool> check = vector<bool>(x + 1, false);
    vector<long long> vals = vector<long long>(x + 1);

    for (int i = 0; i < n; i ++) {
        long long coin;
        cin >> coin;
        coins.push_back(coin);
    }

    cout << solve(x, coins, check, vals);
    
    return 0;
}