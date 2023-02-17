#include <bits/stdc++.h>

using namespace std;

// n - 1
// n - 2 * 2
// n - 3

int main() {

    long long n;
    cin >> n;
    long long s = 0;

    for (int i = 0; i<n; i ++) {
        s += (i + 1) * (n - i - 1);
    }

    cout << s + n << endl;

    return 0;
}