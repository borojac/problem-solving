#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long x) {
    if (x == 2) {
        return true;
    }
    if (x == 3) {
        return true;
    }
    if (x == 1) {
        return false;
    }
    if (x % 2 == 0) return false;
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++) {
        long long x;
        cin >> x;

        long long sx = (long long) sqrt(x);
        if (sx * sx == x && isPrime(sx)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}