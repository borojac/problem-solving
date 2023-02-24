#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    cout << s.size() << "\n";
}