#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("test_input.txt", "r", stdin);
    // freopen("test_output.txt", "w", stdout);

    multiset<long long> h;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        h.insert(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        auto it = h.upper_bound(x);

        if (it == h.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            --it;
            cout << *it << endl;
            h.erase(it);
        }
    }

    return 0;
}