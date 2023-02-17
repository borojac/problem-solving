#include <bits/stdc++.h>

using namespace std;


int main() {
    
    cout << (long long) 3.999999999998 << endl;
    int t;
    cin >> t;
    for (int i = 0; i < t; i ++) {
        // S / n == X / (n - 2) => n*X = S * (n - 2) => X = S * (n - 2) / n;
        vector<long long> arr;
        int n;
        cin >> n;
        double sum = 0;
        map<long long, long long> mp;
        for (int i = 0; i < n; i ++) {
            long long x;
            cin >> x;
            arr.push_back(x);
            mp[x] ++;

            sum += x;
        }

        double X = ((double)sum * (double)(n - 2)) / (double)(n);
        double target = sum - X;

        // double intPart;
        // if (modf(target, &intPart) != 0.0) {
        //     cout << 0 << endl;
        //     continue;
        // }
        if (!((target - (long long) target) < 1e-13 || (target - (long long) target) > (1 - 1e-13))) {
            cout << 0 << endl;
            continue;
        }
        long long cnt = 0;
        long long tg = (long long) target;

        for (int i = 0; i < arr.size(); i ++) {
            mp[arr[i]] --;
            int res = mp[tg - arr[i]];
            if (res > 0)
            cnt += res;
        }

        cout << cnt << endl;
    }



    return 0;
}