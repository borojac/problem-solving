#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i ++) {
        int x;
        cin >> x;
        int limit = sqrt(x);
        int cnt = 0;
        for (int j = 1; j <= limit; j ++) {
            if (x % j == 0)
                cnt += 2;
        }
        if (limit * limit == x)
            cnt --;
        cout << cnt << endl;
    }

    return 0;
}