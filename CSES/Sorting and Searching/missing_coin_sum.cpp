#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long summ = 0;
    int n;
    cin >> n;
    vector<long long> arr;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (summ + 1 < arr[i])
        {
            break;
        }
        summ += arr[i];
    }

    cout << summ + 1;
    return 0;
}