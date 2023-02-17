#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<vector<int>> hist(10);
    // for (int i = 0; i < 10; i ++) hist[i] = 0;

    int n;
    cin >> n;
    vector<string> arr;
    for (int i =0; i < n; i++) {
        string x;
        cin >> x;
        arr.push_back(x);
        for (int j = 0; j < x.size(); j ++) {
            hist[x[j]-'0'].push_back(j);
        }
    }

    int minn = 10000000;
    int target = -1;
    for (int i = 0; i < hist.size(); i ++) {
        sort(hist[i].begin(), hist[i].end());
        for (int l = 0; l < 300; l ++)
        for (int j = hist[i].size() - 1; j >= 0; j --) {
            if (j == hist[i].size() - 1) continue;
            if (hist[i][j] == hist[i][j+1]){
                hist[i][j+1]+= 10;
            }
        }
        int tmp = -1;
        tmp = *max_element(hist[i].begin(), hist[i].end());
        if (tmp < minn)  {
            minn = tmp;
            // target = *max_element(hist[i].begin(), hist[i].end());    
         }
    }

    cout << minn;

    return 0;
}