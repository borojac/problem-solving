#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int k = 0; k < t; k ++) {
        vector<int> arr;
        int n;
        cin >> n;

        for (int j = 0; j < n; j ++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        int i1 = 0, i2 = n - 1;
        int n1 = -1, n2 = -1;
        while (i1 < i2) {
            if (arr[i1] == arr[i2]) {
                i1 ++;
                i2 --;
            } else {
                n1 = arr[i1];
                n2 = arr[i2];
                break;
            }   
        }

        if (i1 >= i2) {
            cout << "YES" << endl;
            continue;
        }

        i1 = 0, i2 = n - 1;
        while (i1 < i2) {
            if (arr[i1] == arr[i2]) {
                i1 ++;
                i2 --;
            } else {
                if (arr[i1] == n1){
                    i1 ++;
                } else if (arr[i2] == n1) {
                    i2 --;
                } else {
                    break;
                }
            }
        }

        if (i1 >= i2) {
            cout << "YES" << endl;
            continue;
        }


        i1 = 0, i2 = n - 1;
        while (i1 < i2) {
            if (arr[i1] == arr[i2]) {
                i1 ++;
                i2 --;
            } else {
                if (arr[i1] == n2){
                    i1 ++;
                } else if (arr[i2] == n2) {
                    i2 --;
                } else {
                    break;
                }
            }
        }
        if (i1 >= i2) {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }

    return 0;
}