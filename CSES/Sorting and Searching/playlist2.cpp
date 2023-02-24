#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int, vector<int>> mp;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }

    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
    }

    return 0;
}