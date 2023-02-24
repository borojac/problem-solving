#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

void solve(vector<int> &c, int ii, int summ)
{
    if (summ == 0)
    {
        cnt++;
        return;
    }

    for (int i = ii; i < c.size(); i++)
    {
        if (summ - c[i] < 0)
        {
            break;
        }
        summ -= c[i];
        solve(c, i, summ);
        summ += c[i];
    }
}

int main()
{

    int n, x;
    cin >> n >> x;

    vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    sort(coins.begin(), coins.end());

    solve(coins, 0, x);

    cout << cnt << endl;

    return 0;
}