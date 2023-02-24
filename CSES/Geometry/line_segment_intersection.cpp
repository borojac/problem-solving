#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long double dist(long double x1, long double y1, long double x2, long double y2) {
    return sqrtl(powl(x2 - x1, 2) + powl(y2 - y1, 2));
}

long double heron(long double a, long double b, long double c) {
    long double s = (a + b + c) / 2;
    return sqrtl(s * (s - a) * (s - b) * (s - c));
}

bool tmpEq(double x1, double y1, double x2, double y2) {
    return abs(x1 - x2) < 1e-10 && abs(y1 - y2) < 1e-10;
}

bool tmpEqNum(double a, double b) {
    return abs(a - b) < 1e-10;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i ++) {
        double x1, x2, x3, x4, y1, y2, y3, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (tmpEq(x1, y1, x3, y3) || tmpEq(x1, y1, x4, y4) || tmpEq(x2, y2, x3, y3) || tmpEq(x2, y2, x4, y4)) {
            cout << "YES\n";
            continue;
        }
        // y - y1 = k * (x - x1) => y = k * x - k * x1 + y1 => y = k * x + (y1 - k * x1)

        // y = k1 * x + n1
        // y = k2 * x + n2 => k1 * x + n1 = k2 *x + n2 => x * (k1 - k2) = n2 - n1 => x = (n2 - n1) / (k1 - k2)

        double k1 = (y2 - y1) / (x2 - x1);
        double k2 = (y4 - y3) / (x4 - x3);

        double n1 = (y1 - k1 * x1);
        double n2 = (y3 - k2 * x3);
        if (x2 - x1 == 0 && x4 - x3 == 0 && x1 == x3) {
            double xf = min(min(y1, y2), min(y3, y4));
            double xl = max(max(y1, y2), max(y3, y4));
            double d = xl - xf;
            double d1 = abs(y2 - y1);
            double d2 = abs(y4 - y3);
            if (abs(d - d1 - d2) < 1e-10) {
                if (y1 == y3 || y1 == y4 || y2 == y3 || y2 == y4) {
                    cout << "YES\n";
                    continue;
                } else {
                    cout << "NO\n";
                    continue;
                }
            } else if (d < d1 + d2) {
                cout << "YES\n";
                continue;
            } else if (d > d1 + d2) {
                cout << "NO\n";
                continue;
            }
        } else if (x2 - x1 == 0 && x4 - x3 == 0 && x1 != x3) {
            cout << "NO\n";
            continue;
        } else if (abs(k1 - k2) < 1e-10) {
            if (abs(n1-n2) > 1e-10) {
                cout << "NO\n";
                continue;
            }
            double xf = min(min(x1, x2), min(x3, x4));
            double xl = max(max(x1, x2), max(x3, x4));
            double d = xl - xf;
            double d1 = abs(x2 - x1);
            double d2 = abs(x4 - x3);
            if (abs(d - d1 - d2) < 1e-10) {
                if (x1 == x3 || x1 == x4 || x2 == x3 || x2 == x4) {
                    cout << "YES\n";
                    continue;
                } else {
                    cout << "NO\n";
                    continue;
                }
            } else if (d < d1 + d2) {
                cout << "YES\n";
                continue;
            } else if (d > d1 + d2) {
                cout << "NO\n";
                continue;
            }
        } else {
            double x;
            if (x2 - x1 == 0)
                x = x1;
            else if (x4 - x3 == 0)
                x = x3;
            else
            x = (n2 - n1) / (k1 - k2);
            double y;
            if (x2 - x1 == 0) {
                y = k2 * x + n2;
            } else {
                y = k1 * x + n1;
            }
            
            if (tmpEq(x, y, x1, y1) || tmpEq(x, y, x2, y2)) {
                
                if (x <= max(x3, x4) && x >= min(x3, x4) && y <= max(y3, y4) && y >= min(y3, y4)) {
                    cout << "YES\n";
                    continue;
                }
            } else if (tmpEq(x, y, x3, y3) || tmpEq(x, y, x4, y4)) {
                if (x <= max(x1, x2) && x >= min(x1, x2) && y <= max(y1, y2) && y >= min(y1, y2)) {
                    cout << "YES\n";
                    continue;
                }
            }
            if ((x <  max(x1, x2) || tmpEqNum(x, max(x1, x2))) && (x > min(x1, x2) || tmpEqNum(x, min(x1, x2))) && (y < max(y1, y2) || tmpEqNum(y, max(y1, y2))) && (y > min(y1, y2) || tmpEqNum(y, min(y1, y2)))) {
                if ((x < max(x3, x4) || tmpEqNum(x, max(x3, x4))) && (x > min(x3, x4) || tmpEqNum(x, min(x3, x4))) && (y < max(y3, y4) || tmpEqNum(y, max(y3, y4))) && (y > min(y3, y4) || tmpEqNum(y, min(y3, y4)))) {
                    cout << "YES\n";
                    continue;
                }
            }
            cout << "NO\n";
        }
    }

    return 0;
}