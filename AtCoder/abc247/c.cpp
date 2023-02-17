#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, string> mp;
    mp[1] = "1";
    for (int i = 2; i <= 16; i ++) {
        mp[i] = mp[i - 1] + " " + to_string(i) + " " + mp[i - 1];
    }

    int n;
    cin >> n;

    cout << mp[n];

    return 0;
}