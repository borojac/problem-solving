#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, x;
    cin >> n >> x;

    long long arr[n];
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int fr = 0, ls = n - 1;
    int cnt = 0;

    while (fr <= ls) {
        if (arr[fr] + arr[ls] <= x) {
            cnt += 1;
            fr ++;
            ls --;
        } else {
            cnt ++;
            ls --;
        }
    }

    cout << cnt;

    return 0;
}