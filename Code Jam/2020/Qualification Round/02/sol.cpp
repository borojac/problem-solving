#include <bits/stdc++.h>

#define toDigit(c) (c-'0')

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, lvlO = 0, lvlC = 0;
    cin >> t;
    
    vector<string> ansV;
    vector<string> strV;
    for (int i = 0; i < t; i ++) {
        int lvlO = 0, lvlC = 0;
        string tmp, ans = "";
        cin >> tmp;
        strV.push_back(tmp);
    }

    for (int i = 0; i < t; i ++) {
        string tmp = strV[i], ans = "";
        for (auto c : tmp) {
            int ci = toDigit(c);
            if (lvlO == ci){
                ans += to_string(ci);
                continue;
            }
            for (; lvlO < ci; lvlO++, lvlC--)
                ans += "(";
            if (lvlO == ci) {
                ans += to_string(ci);
                continue;
            }
            for (; lvlO > ci; lvlC ++, lvlO --)
                ans += ")";
            if (lvlO == ci) {
                ans += to_string(ci);
                continue;
            }
        }
        for (; lvlC != 0; lvlC ++, lvlO --)
            ans += ")";

        ansV.push_back(ans);
    }
    for (int i = 0; i < t; i ++){
        cout << "Case #" << i + 1 << ": " << ansV[i];
        if (i != t - 1)
            cout << endl;
    }
}