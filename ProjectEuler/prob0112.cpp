#include <bits/stdc++.h>

using namespace std;

bool isBouncy(long long x) {
    int ld = x % 10;
    x /= 10;
    bool a = false, b = false;
    while (x) {
        int cd = x % 10;
        if (cd > ld) {
            a = true;
        } else if (cd < ld) {
            b = true;
        }
        ld = cd;
        x /= 10;
    }
    return a && b;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long limit = 1800000;
    long long cnt = 0;
    for (int i = 100; i <= limit ; i ++) {
        if (isBouncy(i)) {
            cnt ++;
        }
        if ((double)cnt / i == 0.99) {
            cout << i;
            break;
        }
        // cout << i << " " << (double)cnt / i << endl;
    }

    return 0;
}