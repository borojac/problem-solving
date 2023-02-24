#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long arr[n];
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }

    for (int i = 0; k + i < n + 1; i ++) {
        vector<int> tmp;
        for (int j = i; j < i + k; j ++) {
            tmp.push_back(arr[j]);
        }
        sort(tmp.begin(), tmp.end());
        long long tmpSum = 0;
        int median;
        if (k % 2 == 0) {
            median = (tmp[k / 2] + tmp[k / 2 - 1]) / 2;
        } else {
            median = tmp[k / 2];
        }
        for (int t : tmp)
            tmpSum += abs(t - median);
        cout << tmpSum << " ";
    }


    return 0;
}