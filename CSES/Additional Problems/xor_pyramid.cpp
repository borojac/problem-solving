#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> arr;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        arr.push_back(x);
    }

    for (int i = 0; i < n - 1; i++)
    {
        vector<long long> tmp;
        for (int j = 0; j < arr.size() - 1; j++)
        {
            tmp.push_back(arr[j] ^ arr[j + 1]);
        }
        arr = tmp;
    }
    cout << arr[0];
    return 0;
}