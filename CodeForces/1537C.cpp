#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k ++){
        
        int n;
        cin >> n;
        vector<int> h;

        for (int i = 0;i < n; i++){
            int x;
            cin >> x;
            h.push_back(x);
        }
        sort(h.begin(), h.end());
        if (n == 2) {
            cout << h[0] << " " << h[1] << "\n";
            continue;
        }

        int i1 = -1, minn = INT_MAX;

        for (int i = 1;i < n; i++){
            if(minn > abs(h[i] - h[i - 1])){
                i1 = i;
                minn = abs(h[i] - h[i - 1]);
            }
        }
        
        for (int i = i1; i < n; i++){
            cout << h[i] << " ";
        }

        for(int i = 0; i < i1; i++){
            cout << h[i] << " ";
        }

        cout << "\n";

    }
}