#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> arr(n);
    vector<int> xi, yi;

    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        if (arr[i] == x) xi.push_back(i);
        if (arr[i] == y) yi.push_back(i);
    }
    vector<pair<bool, bool>> status(n, {false, false});
    for (int i = 0; i < xi.size() ; i ++) {
        int ii = xi[i];
        for (int j = ii; j < n; j ++) {
            if (arr[j] > x) break;
            status[j].first = true;
        }

        for (int j = ii-1; j>=0; j --) {
            if (arr[j] > x) break;
            status[j].first = true;
        }
    }

    for (int i = 0; i < yi.size() ; i ++) {
        int ii = yi[i];
        for (int j = ii; j < n; j ++) {
            if (arr[j] < y) break;
            status[j].second = true;
        }

        for (int j = ii-1; j>=0; j --) {
            if (arr[j] < y) break;
            status[j].second = true;
        }
    }

    long long summ = 0;
    for (int i = 0; i < n; i++) {
        if (status[i].first && status[i].second)    {
            int j = i;
            for (j; status[j].first && status[j].second && j < n ; j ++);
            long long cnt = j - i;
            cout << i << " " << j << " " << cnt << "#@#@#\n";
            summ += ((cnt - 1) * (cnt )) / 2 ;
            i += j - 1;
        }
    }


    cout << summ;
    return 0;
}