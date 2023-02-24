#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i ++) {
        int a, b;
        cin >> a >> b;
        if (a % b == 0)
            cout << 0;
        else 
            cout << b - (a % b);
        if (i != t - 1) {
            cout << endl;
        }
    }
}