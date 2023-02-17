#include <bits/stdc++.h>

using namespace std;

// | |B - 0| - |A - B| | = k
// | B - |A - B| | = k
// B - |A - B| = k, B - |A - B| >= 0
// B - (A - B) = k, A-B >= 0  => 2*B - A = k => 2*B = k + A => B = (k + A) / 2;
// B - (B - A) = k, A-B <= 0 => A = k => 0


// |A - B| - B = k , B - |A - B| < 0
// A - B - B = k, za A-B > 0 => -2B = - A + k => 2B = k - A => B = (k - A) / 2;
// B - A - B = k, za A-B < 0 => 

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i ++) {
        int a, k;

        cin >> a >> k;
        
        if (a < k) {
            cout << k - a << endl;
        } else {
            if ((a % 2) == (k % 2)) {
                cout << 0 << endl;
            } else {
                cout << 1 << endl;
            }
        }

    }

    return 0;
}