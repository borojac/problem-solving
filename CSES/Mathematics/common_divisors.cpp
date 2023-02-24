#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0.0);
    cin.tie(0);

    int t;
    cin >> t;
    vector<int> divisors = vector<int>(1e6 + 1, 0);
    for (int i = 0; i < t; i ++) {
        int x;
        cin >> x;
        int limit = sqrt(x);
        for (int j = 1; j <= limit; j ++) {
            if (x % j == 0) {
                divisors[j] ++;
                divisors[x / j] ++;
            }
        }
        if (limit * limit == x)
            divisors[limit] --;
    }

    for (int i = divisors.size() - 1; i >= 1; i --) {
        if (divisors[i] > 1) {
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}