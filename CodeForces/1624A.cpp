#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> arr;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        long long cnt = 0;
        for (int j = 1; j < n; j++)
        {
            cnt += arr[j] - arr[j - 1];
        }
        cout << cnt << endl;
    }

    return 0;
}