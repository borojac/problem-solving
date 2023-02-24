#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long summ = 0;
    int firstNum;
    cin >> firstNum;
    for (int i = 1; i < n; i ++) {
        long long currNum;
        cin >> currNum;
        if (currNum < firstNum) {
            summ += firstNum - currNum;
            currNum = firstNum ;
        }
        firstNum = currNum;
    }

    cout << summ << "\n";
}