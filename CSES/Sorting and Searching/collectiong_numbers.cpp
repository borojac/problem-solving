#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long arr[n];

    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }

    int wrong = 1;
    int maxx = arr[0];
    for (int i = 0; i < n - 1; i ++) {
        if (arr[i] > arr[i + 1] && arr[i] <= maxx)
            wrong ++;
        maxx = max((long long)maxx, arr[i]);
    }
    

    cout << wrong << endl;
    return 0;
}

// 4 2 1 5 3
// 1 2 3 4 5