#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i ++) {
        long long x1, y1,x2,y2,x,y;
        cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

        long long p1x = x - x1;
        long long p1y = y - y1;
        long long p2x = x - x2;
        long long p2y = y - y2;

        long long res = p1x * p2y - p1y * p2x;

        if (res > 0) {
            cout << "LEFT\n";
        } else if (res == 0) {
            cout << "TOUCH\n";
        } else {
            cout << "RIGHT\n";
        }
    }

    return 0;
}