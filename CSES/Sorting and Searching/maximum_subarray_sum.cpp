#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long arr[n];

    long long summ = 0;
    long long best = LONG_LONG_MIN;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        summ = max(arr[i], arr[i] + summ);
        best = max(summ, best);
    }

    cout << best << "\n";
    
    return 0;
}