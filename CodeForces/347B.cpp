#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    bool flag = false;
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        if (arr[i] == i)  {
            cnt ++;
            
        } else{ 
            if (i == arr[arr[i]]) {
                flag = true;
            }
        }
    }
    if (cnt == n) {
        cout << cnt;
    } else {
        cout << cnt + ((flag) ? 2:1);
    }

    return 0;
}