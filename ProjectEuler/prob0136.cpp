#include <bits/stdc++.h>

using namespace std;

int main() {
    int gcnt = 0;
    for (int i = 1; i < 5e7; i++) {
        int num = i;
        int cnt = 0;

        for (int d = 1; d <= sqrt(i); d++) {
            if (i % d == 0) {
                int r = d;
                if ((i / r + r) % 4 == 0) {
                    int k = (i / r + r) / 4;
                    if (r - k > 0) {
                        cnt++;
                    }
                    if (cnt > 1) {
                        break;
                    }
                }
                r = i / d;
                if ((i / d) != d && (i / r + r) % 4 == 0) {
                    int k = (i / r + r) / 4;
                    if (r - k > 0)
                        cnt++;
                    if (cnt > 1) {
                        break;
                    }
                }
            }
        }
        // cout << i << " " << cnt << endl;
        if (cnt == 1) {
            gcnt++;
        }
    }

    cout << gcnt;

    return 0;
}