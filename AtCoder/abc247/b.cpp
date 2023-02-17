#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<string> s, t;

    for (int i = 0; i < n ; i ++) {
        string ss, tt;
        cin >> ss >> tt;
        s.push_back(ss);
        t.push_back(tt);
    }
    bool falsy = false;
    for (int i = 0; i < n; i ++) {
        string a, b;
        a = s[i];
        b = t[i];
        bool f1 = false, f2 = false;
        for (int j  = 0; j < n; j ++) {
            if (i != j) {
                if (s[j] == a || t[j] == a) f1 = true;
                if (s[j] == b || t[j] == b) f2 = true;
            }
        }
        if (f1 && f2) {
            falsy = true;
            break;
        }
    }

    if (falsy) cout <<"No";
    else cout << "Yes";

    return 0;
}