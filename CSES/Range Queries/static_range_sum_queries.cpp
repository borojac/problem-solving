#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    int arr[n];
    long long summ[n];
    long long tSumm = 0;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        tSumm += arr[i];
        summ[i] = tSumm;
    }

    for (int i = 0; i <q ;i ++) {
        int a, b;
        cin >> a >> b;
        cout << summ[b-1] - summ[a-1] + arr[a-1] << "\n";
    }

    return 0;
}