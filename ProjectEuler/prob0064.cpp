#include <bits/stdc++.h>

using namespace std;

int main() {
    int N = 10000;
    // vector<vector<long long>> data;
    int cnt = 0;
    for (long long n = 2; n <= N; n++) {
        long long sqVal = sqrt(n);
        if (sqVal * sqVal == n) continue;
        // vector<long long> seq;

        long long a0 = sqrt(n);
        // seq.push_back(a0);

        long long a = 1;
        long long b = 1;
        long long c = -a0;
        long long d = 1;
        long long tc = c;
        long long td = d;
        for (long long i = 0; i < 5001; i++) {
            long long nd = (n - c * c) / d;
            long long na = 1;
            long long nb = 1;
            long long nc = -c;

            long long ai = ((long long)sqrt(n) + (nc)) / nd;
            nc -= ai * nd;

            c = nc;
            a = na;
            b = nb;
            d = nd;
            if (c == tc && d == td) {
                if (i % 2 == 0) cnt++;
                break;
            }

            // seq.push_back(ai);
        }
        // data.push_back(seq);
    }

    // cout << endl;

    // long long cnt = 0;
    // for (long long i = 0; i < (long long)data.size(); i++) {
    //     long long maxx = -1;
    //     for (long long s = 1; s <= 2500; s++) {
    //         bool flag = true;
    //         for (long long c = 1; c <= s; c++) {
    //             long long target = data[i][c];
    //             if (i == 1) {
    //                 cout << target << " ";
    //             }
    //             for (long long k = c; k < 101; k += s) {
    //                 if (target != data[i][k]) {
    //                     flag = false;
    //                 }
    //             }
    //             if (!flag) break;
    //         }
    //         if (flag) {
    //             maxx = s;
    //             break;
    //         }
    //     }
    //     if (maxx % 2 == 1) {
    //         cnt++;
    //     }
    // }

    cout << endl
         << "Result: " << endl;
    cout << cnt << endl;

    return 0;
}