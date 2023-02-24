#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long target;
    cin >> target;
    
    long long arr[n];
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }

    int i1 = 0, i2 = 0;
    long long summ = arr[i1];
    long long cnt = 0;

    while (true) {
        if (summ == target) {
            cnt ++;
            i2 ++;
            summ += arr[i2];
            summ -= arr[i1];
            i1 ++;
        } else if (summ < target) {
            i2 ++;
            summ += arr[i2];
        } else {
            summ -= arr[i1];
            i1 ++;
        }

        if (i1 == i2 && summ > target) {
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