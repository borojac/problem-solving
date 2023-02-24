#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("codejam1c/02/input.txt", "r", stdin);
    freopen("codejam1c/02/output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt ++) {
        int n, d;
        cin >> n >> d;
        vector<long long> cuts;
        unordered_map<long long, long long> mp;
        long long slices = 0;
        int maxx = 0;
        for (int i = 0; i < n; i ++) {
            long long ai;
            cin >> ai;
            cuts.push_back(ai);
            mp[ai] ++;
            long long tmp = mp[ai];
            if (tmp > maxx)
                maxx = tmp;
        }
        
        long long slices1 = LONG_LONG_MAX;
        long long slices2 = LONG_LONG_MAX;
        long long slices3 = LONG_LONG_MAX;
        long long slices4 = INT_MAX;

        sort(cuts.begin(), cuts.end());
        bool found = false;
        if (maxx < d) {
            long long localMin = INT_MAX;
            
            for (int i = 0; i < n; i ++) {
                long long tmpS = mp[cuts[i]];
                int tmpSlices = 0;
                for (int j = i + 1; j < n; j ++) {
                    if (cuts[i] != cuts[j]) {
                        if (cuts[j] % cuts[i] == 0) {
                            long long col = cuts[j] / cuts[i];
                            tmpS += col;
                            tmpSlices += col - 1;
                        }
                        if (tmpS >= d) {
                            found = true;
                            slices1 = tmpSlices;
                            break;  
                        }
                    }
                }
                if (found) {
                    break;
                }
            }
                long long fir = cuts[0];
                long long tmpS = 1;
                long long tmpSlices = 0;
                long long uk = 0;
                long long po;
                for (int i = 1; i < n; i ++) {

                    long long col = cuts[n-i-1] / fir;
                    
                    if (d % n-i-1 > 0)
                        po = 1 + d / i;
                    else
                        po = d / i;
                    
                    uk += col;
                    tmpS += col;
                    
                    long long tmpsl = tmpS - (tmpS - d);
                    if (tmpsl < slices4)
                        slices4 = tmpsl;
                    if (tmpS > d) {
                        found = true;
                        tmpSlices = tmpS - (tmpS - d);
                        break;
                    }
                }
                if (found)
                    slices2 = tmpSlices;
                po = 0;
                if (d % maxx > 0) {
                    po = 1 + d / maxx;
                } else
                    po = d / maxx;
                slices3 = maxx * (po - 1);
                for (int i = mp[cuts[0]], slices = 0; i <= uk; i ++, slices ++) {
                    
                }
            
        } else {
            cout << "Case #" << tt + 1 << ": " << 0 << endl;    
            continue;
        }
            cout << "Case #" << tt + 1 << ": " << min(min(min(slices1, slices2), slices3), slices4) << endl;
    }
}