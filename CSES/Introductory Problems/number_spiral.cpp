#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0.0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        long long x,y;
        cin >> y;
        cin >> x;

        long long diag_el = 1 + max(x-1, y-1)*(max(x-1, y-1)+1);
        // cout << diag_el << "\n";
        int sign = max(x, y) % 2 ? 1 : -1;

        if (x == y){
            cout << diag_el << "\n";
            continue;
        }
        if (y < x){
            diag_el += sign * (x - y);
        }
        else{
            diag_el -= sign * (y - x);
        }
        cout << diag_el << "\n";
    }
    return 0;
}