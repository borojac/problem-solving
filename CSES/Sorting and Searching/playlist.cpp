#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    freopen("test_input.txt", "r", stdin);

    // set<long long> tmp;
    map<int, int> mp;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int lastI = 0;
    int maxx = 0;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        // auto it = tmp.find(arr[i]);

        if (mp[arr[i]] == 0)
        {
            // tmp.insert(arr[i]);
            cnt++;
            mp[arr[i]] = cnt;
        }
        else
        {
            if (cnt > maxx)
            {
                maxx = cnt;
            }
            i -= (cnt - mp[arr[i]] + 1);
            cnt = 0;
            mp.clear();
        }
    }
    if (cnt > maxx)
    {
        cout << cnt;
    }
    else
    {
        cout << maxx << endl;
    }

    return 0;
}