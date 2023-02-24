#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

int main() {
    // auto start = high_resolution_clock::now();
    cin.tie(0)->sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);

    int n;
    long long x;
    cin >> n >> x;

    long long arr[n], tmpArr[n];
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        tmpArr[i] = arr[i];
    }

    sort(tmpArr, tmpArr + n);
    bool exists = false;
    long long a, b, c, d;
    for (int i = 0; i < n - 3; i ++) {
        if (tmpArr[n - 1] + tmpArr[n - 2] + tmpArr[n - 3] + tmpArr[i] < x)
            continue;
        for (int j = i + 1; j < n - 2; j ++) {
            if (tmpArr[n - 1] + tmpArr[n - 2] + tmpArr[i] + tmpArr[j] < x)
                continue;
            long long target = x - tmpArr[i] - tmpArr[j];
            int i1 = j + 1;
            int i2 = n - 1;
            while (i1 < i2) {
                if (target > tmpArr[i1] + tmpArr[i2]) {
                    i1 ++;
                } else if (target == tmpArr[i1] + tmpArr[i2]) {
                    exists = true;
                    a = tmpArr[i];
                    b = tmpArr[j];
                    c = tmpArr[i1];
                    d = tmpArr[i2];
                    break;
                } else {
                    i2 --;
                }
            }

            if (exists) {
                break;
            }
        }
        if (exists) {
            break;
        }
    }

    if (!exists) {
        cout << "IMPOSSIBLE";
    } else {
        bool aa = false, bb = false, cc = false, dd = false;
        for (int i = 0; i < n; i ++) {
            if (!aa) {
                if (arr[i] == a) {
                    aa = true;
                    cout << i + 1 << " ";
                    continue;
                }
            }
            if (!bb) {
                if (arr[i] == b) {
                    bb = true;
                    cout << i + 1 << " ";
                    continue;
                }
            }
            if (!cc) {
                if (arr[i] == c) {
                    cc = true;
                    cout << i + 1 << " ";
                    continue;
                }
            }
            if (!dd) {
                if (arr[i] == d) {
                    dd = true;
                    cout << i + 1 << " ";
                    continue;
                }
            }
        }
    }
    
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<milliseconds>(stop - start);
    
    // cout << "Time taken by function: "
        //  << duration.count() << " microseconds" << endl;
    return 0;
}