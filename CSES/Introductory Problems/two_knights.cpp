#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int> mp;
    mp[0] = 0;
    mp[1] = 6;
    mp[2] = 28;
    mp[3] = 28;
    mp[4] = 96;
    mp[5] = 252;
    mp[6] = 550;
    mp[7] = 1056;
    mp[8] = 1848;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        if (i <= 8) {
            cout << mp[i - 1] << "\n";
        } else {
            
        }
    }
    return 0;
}