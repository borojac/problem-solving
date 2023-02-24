#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long res = 0;
    for(int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if(__gcd(arr[i], arr[j]) == 1){
                res ++;
            }
        }
    }
    cout << res;

    return 0;
}