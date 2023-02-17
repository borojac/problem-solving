#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (a + b + c > 1) cnt ++;
    }

    cout << cnt;

    return 0;
}