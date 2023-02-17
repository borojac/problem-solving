#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;
    vector<int> res;
    for (int k = 0; k < t; k ++) {
        int n;
        cin >> n;
        vector<int> arr;
        if (n == 1) {
            res.push_back(1);
            continue;
        }
        int i = 0;
        int resNum = 0;
        int neg = 0;
        int nv = 0;
        int bp = 0;
        for (int i = 0; i < n;i ++) {
            int x;
            cin >> x;
            if (x < 0) {
                neg ++;
            } else if ( x == 0) {
                nv ++;
            } else if (x > 0) {
                bp ++;
            }
        }


        if (nv == 1) {
            if (bp > 0) {
                res.push_back(neg + 2);
            } else {
                res.push_back(neg + 1);
            }
        } else if (nv > 1) {
            res.push_back(neg + nv);
        } else {
            if (bp > 0) {
                res.push_back(neg + 1);
            } else {
                res.push_back(neg);
            }
        }

    }

    for (int i = 0; i < res.size(); i ++) {
        cout << res[i] << endl;
    }



    return 0;
}