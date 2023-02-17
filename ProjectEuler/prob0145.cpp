#include <bits/stdc++.h>

using namespace std;

long long revert(long long num) {
    long long rv = 0;
    if (num % 10 == 0) {
        return -1;
    }
    while (num) {
        int digit = num % 10;
        rv += digit;
        rv *= 10;
        num /= 10;
    }
    rv /= 10;
    return rv;
}

bool check(long long num) {
    while (num) {
        int digit = num % 10;
        if (digit % 2 == 0) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("output.txt", "w", stdout);
    long long limit = 1e3;
    long long cnt = 0;
    for (long long i = 1; i <= limit; i ++) {
        long long rv = revert(i);
        if (rv == -1) {
            continue;
        }

        long long nn = rv + i;
        if (check(nn)) {
            cnt ++;
        }

    }
    
    cout << cnt;
    return 0;
}