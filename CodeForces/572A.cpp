#include <bits/stdc++.h>

using namespace std;

int main() {
    int n1, n2;
    int k, m;
    cin >> n1 >> n2 >> k >> m;

    int num1 ;
    for (int i = 0; i < n1; i ++) {
        int x;
        cin >> x;
        if (i == k - 1) {
            num1 = x;
        }
    }
    int num2;
    for (int i = 0; i < n2; i ++) {
        int x;
        cin >> x;
        if (n2 - m == i) {
            num2 = x;
        }
    }

    if (num2 > num1) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}