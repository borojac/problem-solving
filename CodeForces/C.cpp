#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("CodeForces/input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    char arr[n][m];
    bool flag = false;
    int beg;
    int cnt = 0;
    int f, l;
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        int fr = s.find_first_of("B");
        int ls = s.find_last_of("B");

        if (!flag && fr >= 0){
            beg = i;
            f = fr;
            l = ls;
            break;
        }

    }
    if (l - f  == 0){
        cout << beg + 1 << " " << f + 1;
    }else {
        cout << (beg + (l-f) / 2) + 1 << " " <<  (l - f)/2 + f + 1;
    }
}