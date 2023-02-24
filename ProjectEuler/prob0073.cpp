#include <bits/stdc++.h>

using namespace std;

int main() {
    int limit = 12000;
    vector<double> arr;
    for (int i = 2; i <= limit; i++) {
        for (int j = 1; j < i; j++) {
            if (__gcd(j, i) == 1) {
                arr.push_back((double)(j) / (double)(i));
            }
        }
    }

    sort(arr.begin(), arr.end());
    double err = 1e-10;
    int ii = 0;
    for (;; ii++) {
        if (abs(arr[ii] - (double)1 / 3) < err) {
            break;
        }
    }
    int i1 = ii;
    for (;; ii++) {
        if (abs(arr[ii] - (double)1 / 2) < err) {
            break;
        }
    }

    int i2 = ii;
    cout << i2 - i1 - 1 << endl;
}