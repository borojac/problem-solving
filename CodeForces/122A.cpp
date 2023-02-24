#include <bits/stdc++.h>

using namespace std;

bool che(int n) {
    while (n > 0) {
        int d = n % 10;
        if (d != 4 && d != 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main() {
    vector<int> lnn;
    for (int i = 1; i<=1000;i ++) {
        if (che(i)) {
            lnn.push_back(i);
        }
    }

    int n;
    cin >> n;
    bool flag = false;
    for (int i = 0; i < lnn.size(); i ++) {
        if (n % lnn[i] == 0) {
            cout << "YES";
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "NO";
    }
}