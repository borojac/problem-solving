#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int mod = n % 4;
    vector<int> s1, s2;
    if (mod == 2 || mod == 1) {
        cout << "NO" << "\n";
        return 0;
    } else if (mod == 0) {
        for (int i = 0; i < n / 2; i ++) {
            if (i % 2 == 0)
                s1.push_back(i + 1);
            else
                s2.push_back(i + 1);
        }

        for (int i = n - 1; i >= n / 2; i --) {
            if (i % 2 == 1)
                s1.push_back(i + 1);
            else
                s2.push_back(i + 1);
        }
    } else {
        s1.push_back(n);
        for (int i = 1; i <= (n + 1) / 4; i ++) {
            s2.push_back(i);
            s2.push_back(n - i);
        }
        for (int i = (n + 1) / 4 + 1; i < (n + 1) / 2; i ++) {
            s1.push_back(i);
            s1.push_back(n - i);
        }

    }
    cout << "YES" << "\n";
    cout << s1.size() << "\n";
    for (int i : s1)
        cout << i << " ";
    cout << "\n";
    cout << s2.size() << "\n";
    for (int i : s2)
        cout << i << " ";
    return 0;
}