#include <bits/stdc++.h>

using namespace std;

int main() {
    long long M = 1817;
    int cnt = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = i; j <= M; j++) {
            for (int k = j; k <= M; k++) {
                double a1 = i + k;
                double b1 = j;
                double a2 = j + k;
                double b2 = i;
                double a3 = i + j;
                double b3 = k;
                double c1 = sqrt(a1 * a1 + b1 * b1);
                double c2 = sqrt(a2 * a2 + b2 * b2);
                double c3 = sqrt(a3 * a3 + b3 * b3);
                // if (i == 3 && j == 5 && k == 6) {
                // cout << c1 << " " << c2 << " " << c3 << endl;
                // }
                double minC = min(min(c1, c2), c3);
                double intpart;
                if (modf(minC, &intpart) == 0.0) {
                    // cout << i << " " << j << " " << k << endl;
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}