#include <bits/stdc++.h>

using namespace std;

bool solve(int x, int beg, vector<int>& coins, bool* check[]) {
    if (x == 0) {
        return true;
    }
    if (x < 0 || beg == (int)coins.size()) {
        return false;
    }
    for (int i = beg; i >= 0; i --) {
        if (check[beg][x])
            return true;
    }
    // if (check[beg][x])
    //     return true;
    bool flag = false;
    for (int i = beg; i < (int)coins.size(); i++) {
        flag = solve(x - coins[i], i + 1, coins, check);
        if (flag)
            break;
    }

    if (flag) {
        for (int i =  0; i <= beg; i ++) {
            check[beg][x] = true;
        }
    }

    return flag;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> coins;
    int summ = 0;
    for (int i  = 0; i < n; i ++) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
        summ += coin;
    }

    sort(coins.begin(), coins.end());
    
    bool** check;
    check = new bool* [n];
    for (int i = 0; i < n; i ++)
        check[i] = new bool[summ + 1]{false};

    vector<int> sums;

    for (int i = 1; i <= summ; i ++) {
        if (solve(i, 0, coins, check)) {
            sums.push_back(i);
        }
    }
    cout << sums.size() << "\n";
    for (int i : sums) {
        cout << i << " ";
    }

    return 0;
}