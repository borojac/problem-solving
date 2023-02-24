#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    long long arr[n], arr2[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr2[i] = arr[i];
    }

    sort(arr, arr + n);

    long long i1 = 0, i2 = n - 1;
    while (i1 < i2)
    {
        if (arr[i1] + arr[i2] > k)
        {
            i2--;
        }
        else if (arr[i1] + arr[i2] < k)
        {
            i1++;
        }

        else
        {
            break;
        }
    }
    if (i1 < i2) {
        long long  f = arr[i1];
        long long l = arr[i2];
        i1 = -1;
        i2 = -1;
        bool flag1 = false; bool flag2 = false;
        for (int i = 0; i < n; i ++) {
            if (f == arr2[i] && !flag1) {
                if (i + 1 != i2) {
                    i1 = i + 1;
                    flag1 = true;
                }
            }
            if (l == arr2[i] && !flag2) {
                if (i + 1 != i1) {
                    i2 = i + 1;
                    flag2 = true;
                }
            }
        }
        cout << i1 << " " << i2;
    }
    else
        cout << "IMPOSSIBLE";

    return 0;
}