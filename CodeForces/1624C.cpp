#include <bits/stdc++.h>

using namespace std;

void printVec(vector<int> v)
{
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

bool solved = false;

void solve(vector<vector<int>> &mp, vector<bool> &visited, int rb)
{
    if (rb == (int)visited.size() + 2)
    {
        solved = true;
        return;
    }
    if (solved)
        return;
    for (int i = 0; i < mp.size(); i++)
    {
        if (visited[i])
            continue;
        if (binary_search(mp[i].begin(), mp[i].end(), rb))
        {
            visited[i] = true;
            solve(mp, visited, rb + 1);
            if (solved)
                return;
            visited[i] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n;
        cin >> n;
        vector<vector<int>> mp(n);
        set<long long> st;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            long long xx = x;
            while (xx > 0)
            {
                if (xx <= n && xx != 1)
                {
                    mp[i].push_back(xx);
                    st.insert(xx);
                }
                xx /= 2;
            }
        }
        if (st.size() < n - 1)
        {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            sort(mp[i].begin(), mp[i].end());
        }
        solved = false;
        vector<bool> visited(n - 1, false);
        solve(mp, visited, 2);
        if (solved)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}