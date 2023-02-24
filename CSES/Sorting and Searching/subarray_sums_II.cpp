#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long target;
    cin >> target;
    // 2 6 8 = > 16 - 7 = 9
    long long arr[n];
    long long minn = (long long) 1e11;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        if (arr[i] < minn)
            minn = arr[i];
    }

    long long forAdd = 1 - minn;
    if (minn <= 0) {
        for (int i = 0; i < n; i++) {
            arr[i] += forAdd;
            cout << arr[i] << " ";
        }
        cout << endl;
        // target += n*forAdd;
    }

    int i1 = 0, i2 = 0;
    long long summ = arr[i1];
    long long cnt = 0;

    while (true) {
        if (summ == target + (i2 - i1 + 1) * forAdd) {
            cout << summ << " " << i1 << " " << i2 << endl;
            cnt ++;
            i2 ++;
            summ += arr[i2];
            summ -= arr[i1];
            i1 ++;
        } else if (summ < target + (i2 - i1 + 1) * forAdd) {
            i2 ++;
            summ += arr[i2];
        } else {
            summ -= arr[i1];
            i1 ++;
        }

        if (i1 == i2 && summ > target + (i2 - i1 + 1) * forAdd) {
            i1 ++;
            i2 ++;
            if (i1 < n)
                summ = arr[i1];
            else 
                break;
        }
        if (i2 == n)
            break;
    }

    cout << cnt;

    return 0;
}