#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<long long, long long> mp;
    long long limit = 1500000;
    for (long long a = 1; a <= limit; a++) {
        if (a % 1000 == 0) cout << a << endl;
        for (long long b = a; b <= limit; b++) {
            long long c = sqrtl(a * a + b * b);
            if (c * c == a * a + b * b) {
                mp[a + b + c]++;
            }
        }
    }
    int cnt = 0;
    for (long long i = 0; i <= limit; i++) {
        if (mp[i] == 1) cnt++;
    }
    // 40 min 46 sec run time

    cout << cnt << endl;
    return 0;
}