#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; long long x;
    cin >> n >> x;
    long long arr[n], arr2[n];
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }

    sort(arr, arr + n);
    long long a, b, c;
    bool exists = false;
    for (int i = 0; i < n - 2; i ++) {
        for (int j = i + 1; j < n - 1; j ++) {
            long long tn = x - arr[i] - arr[j];
            exists = binary_search(arr + j + 1, arr + n, tn);
            if (exists) {
                a = arr[i];
                b = arr[j];
                c = tn;
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
        bool f = false, s = false, t = false;
        for (int i = 0; i < n; i ++) {
            if (!f) {
                if (arr2[i] == a) {
                    f = true;
                    cout << i + 1 << " ";
                    continue;
                }
            }
            if (!s) {
                if (arr2[i] == b) {
                    s = true;
                    cout << i + 1 << " ";
                    continue;
                }
            }
            if (!t) {
                if (arr2[i] == c) {
                    t = true;
                    cout << i + 1 << " ";
                    continue;
                }
            }
        }
    }

    return 0;
}