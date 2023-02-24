#include <bits/stdc++.h>

using namespace std;

vector<long long> getFactors(long long n) {
    vector<long long> res;
    for (int i = 2; i*i <= n; i ++) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        res.push_back(n);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0.0);
    cin.tie(0);

    long long n;
    cin >> n;
    long long gMul = 0;
    for (int ii = 2; ii <= n; ii ++) {
        vector<long long> factors = getFactors(ii);
        long long mul = 1;
        long long last = factors[0];
        int cnt = 1;
        for (int i = 1; i < (int)factors.size(); i ++) {
            if (last == factors[i]) {
                cnt ++;
                continue;
            }
            mul *= (pow(last, cnt + 1) - 1);
            mul /= last - 1;
            mul %= (long long)1e9+7;
            last = factors[i];
            cnt = 1;
        }
        
        mul *= (pow(last, cnt + 1) - 1);
        mul /= last - 1;
        mul %= (long long)1e9+7;
        gMul += mul;
    }
    gMul += 1;
    gMul %= (long long)1e9 + 7;
    cout << gMul;

    return 0;
}