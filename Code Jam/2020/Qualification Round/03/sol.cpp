#include <bits/stdc++.h>

using namespace std;

struct tt { 
    int x, y, index;
    char t;
    bool operator<(const tt& t){
        return x < t.x;
    }
};


bool comp(tt t1, tt t2){
    return t1.index < t2.index;
}

bool checkImpossible(vector<tt> arr) {
    int hist[24 * 60 + 1] = {0};
    for (tt a : arr){
        for (int i = a.x; i < a.y; i ++)
            hist[i] ++;
    }
    if (*max_element(hist, hist + 24 * 60 + 1) > 2)
        return true;
    return false;
}

// bool checkOverlap(tt t1, tt t2) {
//     int hist[24 * 60] = {0};
//     for (int i = t1.x; i < t1.y; i ++)
//         hist[i] ++;
//     for (int i = t2.x; i < t2.y; i ++)
//         hist[i] ++;
//     return *max_element(hist, hist + 24 * 60) == 2;
// }

bool checkAvail(int arr[], tt t){
    for (int i = t.x; i < t.y; i ++)
    if (arr[i] != 0)
        return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> imp;
    vector<tt> arr[t];
    vector<string> ans;
    for (int i  = 0; i < t; i ++){
        int n;
        cin >> n;
        int index = 0;
        for (int j = 0; j < n; j ++) {
            int x, y;
            cin >> x >> y;
            tt tmp;
            tmp.x = x;
            tmp.y = y;
            tmp.index = index ++;
            arr[i].push_back(tmp);
        }
    }
    
    for (int i  = 0; i < t; i ++) {
        sort(arr[i].begin(), arr[i].end());
        int jHist[60 * 24 + 1] = {0};
        int cHist[60 * 24 + 1] = {0};
        if (checkImpossible(arr[i])){
            imp.push_back(i);
            continue ;
        }
        string ansStr = "C";
        arr[i][0].t = 'C';
        for (int j = arr[i][0].x; j < arr[i][0].y; j ++)
            cHist[j]++;
        for (int j = 1; j < arr[i].size(); j ++){
            bool avC = checkAvail(cHist, arr[i][j]);
            if (avC){
                // ansStr += "C";
                arr[i][j].t = 'C';
                for (int k = arr[i][j].x; k < arr[i][j].y; k ++)
                    cHist[k]++;
            }else {
                bool avJ = checkAvail(jHist, arr[i][j]);
                if (avJ){
                    arr[i][j].t = 'J';
                    // ansStr += "J";
                
                    for (int k = arr[i][j].x; k < arr[i][j].y; k ++)
                        jHist[k]++;
                }
            }
        }
        ans.push_back(ansStr);
    }


    for (int i = 0; i < t; i ++){
        sort(arr[i].begin(), arr[i].end(), comp);
        string answer = "";
        if (count(imp.begin(), imp.end(), i))
            answer = "IMPOSSIBLE";
        else
            for (int j = 0; j < arr[i].size(); j ++)
                answer += arr[i][j].t;
        cout << "Case #" << i + 1 << ": " << answer;
        if (i != t - 1)
            cout << endl;
    }

}