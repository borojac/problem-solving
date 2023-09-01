#include <bits/stdc++.h>

using namespace std;

int equals(double a, double b) {
    if (abs(a - b) < 1e-9) return 0;
    if (a > b) return -1;
    return 1;
}

// LAST IN RESULTING LIST
// LIST WILL APPEAR IN "output.txt" file

int main() {
    freopen("output.txt", "w", stdout);
    deque<pair<double, pair<int, int>>> arr;
    double limit = (double)3 / 7;
    for (int i = 2; i <= 1000000; i++) {
        // if (i % 1000 == 0) {
        //     cout << i << " " << arr.size() << endl;
        // }
        for (int j = i / 3 == 0 ? 1 : i / 3; j < i; j++) {
            double num = (double)j / i;
            int res = equals(num, limit);
            if (res < 0) {
                if (j > 1) arr.push_back({(double)(j - 1) / i, {j - 1, i}});
                break;
            }
        }
    }
    sort(arr.begin(), arr.end());
    vector<pair<double, pair<int, int>>> res;
    for (auto x : arr) {
        // cout << fixed << setprecision(25) << x.first << " | " << x.second.first << " | " << x.second.second << endl;
        if (__gcd(x.second.first, x.second.second) == 1) res.push_back(x);
    }
    for (auto x : res) {
        cout << fixed << setprecision(25) << x.first << " | " << x.second.first << " | " << x.second.second << endl;
    }
    cout << endl;
    return 0;
}