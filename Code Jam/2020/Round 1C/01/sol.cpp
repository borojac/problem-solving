#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("codejam1c/01/input.txt", "r", stdin);
    freopen("codejam1c/01/output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt ++) {
        int x0 = 0, y0 = 0;
        int x, y;
        cin >> x >> y;
        string ppath;
        cin >> ppath;
        int cnt = 0;
        bool found = false;
        for (int i = 0; i < ppath.size(); i ++) {
            // cout << x << " " << y << " " << x0 << " " << y0;
            if (x == x0 && y == y0) {
                cout << "Case #" << tt + 1 << ": " << cnt << endl;
                found = true;
                break;
            }
            char c = ppath[i];
            if (c == 'S') {
                if (x > x0 && y > y0) {
                    x0 += 1;
                    y -= 1;
                } else if (x == x0 && y - y0 > 1) {
                    y0 += 1;
                    y -= 1;
                } else if (y == y0) {
                    y0 -= 1;
                    y -= 1;
                } else if (x == x0 && y - y0 == 1) {
                    y -= 1;
                }
            } else if (c == 'N') {
                if (y > y0 && x > x0) {
                    y0 += 1;
                    y += 1;
                } else if (x == x0 && y > y0) {
                    y += 1;
                    y0 += 1;
                } else if (y == y0) {
                    y0 += 1;
                    y += 1;
                } 
            } else if (c == 'E') {
                if (x > x0) {
                    x += 1;
                    x0 += 1;
                } else if (y == y0) {
                    x += 1;
                    x0 += 1;
                } else if (x == x0) {
                    x += 1;
                    x0 += 1;
                }
            } else if (c == 'W') {
                if (y == y0 && x - x0 == 1) {
                    x -= 1;
                } else if (y > y0 && x > x0){ 
                    y0 += 1;
                    x -= 1;
                } else if (y == y0) {
                    x0 += 1;
                    x -= 1;
                } else if (x == x0) {
                    x0 -= 1;
                    x -= 1;
                }
            }
            cnt ++;
            if (x == x0 && y == y0) {
                cout << "Case #" << tt + 1 << ": " << cnt << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Case #" << tt + 1 << ": IMPOSSIBLE" << endl;
        }
    }

}