#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0.0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    long long apartments[m];
    long long people[n];
    for (int i = 0; i < n; i ++) {
        cin >> people[i];
    }
    
    for (int i = 0; i < m; i ++) {
        cin >> apartments[i];
    }

    sort(people, people + n);
    sort(apartments, apartments + m);

    int i1 = 0, i2 = 0;
    int cnt = 0;
    while (i1 < n && i2 < m) {
        if (abs(people[i1] - apartments[i2]) <= k) {
            cnt ++;
            i1 ++;
            i2 ++;
        }else if (people[i1] > apartments[i2]) {
            i2 ++;
        } else {
            i1 ++;
        }
    }

    cout << cnt;

    return 0;
}