#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }

    deque<pair<int, int>> dq;
    dq.push_back({arr[0], 0});
    cout << 0;
    int cnt = 1;
    for (int i = 1; i < n; i ++) {
        while (!dq.empty() && dq.back().first >= arr[i]) {
            cnt --;
            dq.pop_back();
        }
        if (cnt == 0)
            cout << " 0";
        else
            cout << " " << dq.back().second + 1;
        dq.push_back({arr[i], i});
        cnt ++;
    }

    return 0;
}