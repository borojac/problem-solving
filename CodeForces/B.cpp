#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("CodeForces/input.txt", "r", stdin);

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i ++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        int x1 = x + 1;
        int x2 = x - 1;
        int y1 = y + 1;
        int y2 = y - 1;

        int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
        if (x1 < a){
            p1 = b * (a - x1);
        }
        if (x2 >= 0){
            p2 = b * (x2 + 1);
        }

        if (y1 < b){
            p3 = a * (b - y1);
        }
        if (y2 >= 0){
            p4 = a * (y2 + 1);
        }

        cout << max(max(p1, p2), max(p3, p4));
        if (i != t - 1)
            cout << endl;
    }
}