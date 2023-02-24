#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i ++) {
        int n;
        int diag = 0, tmp;
        cin >> n;

        int arr[n][n];
        for (int j = 0; j < n; j ++){
            for (int k = 0; k < n; k ++) {
                cin >> arr[j][k];
                if (j == k)
                    diag += arr[j][k];
            }
        }
        int rows = 0;
        int cols = 0;

        for (int j = 0; j < n; j ++) {
            int histR[n + 1] = {0};
            int histC[n + 1] = {0};
            for (int k = 0; k < n; k ++){
                histR[arr[j][k]] ++;
                histC[arr[k][j]] ++;
            }
           for (int k = 1; k <= n; k ++){
                if (histR[k] > 1){
                    rows ++;
                    break;
                }
            }

            
           for (int k = 1; k <= n; k ++){
                if (histC[k] > 1){
                    cols ++;
                    break;
                }
            }
        }


    
        cout << "Case #" << i + 1 << ": " << diag << " " << rows << " " << cols;
        if (i != t - 1)
            cout << endl; 
    }
}