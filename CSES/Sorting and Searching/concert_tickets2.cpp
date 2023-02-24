#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<long long> h;
    vector<long long> t;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        h.push_back(x);
    }

    sort(h.begin(), h.end());
    reverse(h.begin(), h.end());
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        t.push_back(x);
    }
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    int ib = 0;
    int ie = h.size();

    for (int i = 0; i < m; i++)
    {
        cout << "Array: ";
        for (int k = 0; k < h.size(); k++)
        {
            cout << h[k] << " ";
        }
        cout << endl;
        if (ib >= h.size())
        {
            cout << -1 << endl;
            continue;
        }
        int x = t[i];
        auto it = lower_bound(h.begin() + ib, h.end(), x, greater<long long>());
        int index = it - h.begin();
        cout << index << endl;
        cout << "x: " << x << endl;

        if (index == h.size() - 1 && h[index] != x)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            if (h[index] == x)
            {
                cout << h[index] << endl;
                ib = index + 1;
            }
            else
            {
                if (index + 1 < h.size())
                {
                    cout << h[index + 1] << endl;
                    ib = index + 2;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
        }
    }

    return 0;
}