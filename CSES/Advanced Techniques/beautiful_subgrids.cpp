#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("test_input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<vector<unsigned long long>> arr;
    for (int i = 0; i < n; i++)
    {
        vector<unsigned long long> tmp;
        arr.push_back(tmp);
        string t;
        cin >> t;
        int icnt = n / 64;
        for (int k = 0; k < icnt; k++)
        {
            int b = t.size() - ((k + 1) * 64);
            arr[i].push_back(stoull(t.substr(b, 64), nullptr, 2));
        }
        if (n % 64 != 0)
        {
            arr[i].push_back(stoull(t.substr(0, n % 64), nullptr, 2));
        }
    }
    long long cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long tmpCnt = 0;
            for (int k = 0; k < arr[i].size(); k++)
            {
                tmpCnt += __builtin_popcountll(arr[i][k] & arr[j][k]);
            }

            cnt += ((tmpCnt - 1) * tmpCnt) / 2;
        }
    }

    cout << cnt << endl;
    return 0;
}