#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> curr;
ll cnt = 0;

map<vector<ll>, ll> sums10;
map<vector<ll>, ll> sums20;

int sum2() {
    if ((int)curr.size() == 0) return 0;
    if ((int)curr.size() == 1) return curr[0];

    return curr[(int)curr.size() - 1] + curr[(int)curr.size() - 2];
}

vector<ll> get2() {
    if ((int)curr.size() == 0) return {0, 0};
    if ((int)curr.size() == 1) return {0, curr[0]};

    return {curr[(int)curr.size() - 2], curr[(int)curr.size() - 1]};
}

int sum22() {
    if ((int)curr.size() == 0) return 0;
    if ((int)curr.size() == 1) return curr[0];

    return curr[0] + curr[1];
}

vector<ll> get22() {
    if ((int)curr.size() == 0) return {0, 0};
    if ((int)curr.size() == 1) return {curr[0], 0};

    return {curr[0], curr[1]};
}

void solve() {
    if ((int)curr.size() == 10) {
        cnt++;
        sums10[get2()]++;
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (i == 0 && (int)curr.size() == 0) continue;
        if (sum2() + i < 10) {
            curr.push_back(i);
            solve();
            curr.pop_back();
        } else {
            break;
        }
    }
}

void solve2() {
    if ((int)curr.size() == 10) {
        cnt++;
        sums20[get22()]++;
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (sum2() + i < 10) {
            curr.push_back(i);
            solve2();
            curr.pop_back();
        } else {
            break;
        }
    }
}

bool f(vector<ll> a, vector<ll> b) {
    return a[0] + a[1] + b[0] <= 9 && a[1] + b[0] + b[1] <= 9;
}

int main() {
    solve();
    cout << "Count for 10: " << cnt << endl;
    cnt = 0;
    curr = {};
    solve2();
    cout << "Count for second 10: " << cnt << endl;
    cnt = 0;

    for (auto it = sums10.begin(); it != sums10.end(); it++) {
        vector<ll> a = it->first;
        ll val = it->second;
        for (auto it2 = sums20.begin(); it2 != sums20.end(); it2++) {
            vector<ll> b = it2->first;
            ll val2 = it2->second;
            if (f(a, b)) {
                cnt += val * val2;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}