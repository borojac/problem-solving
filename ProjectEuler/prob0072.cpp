#include <bits/stdc++.h>

using namespace std;

map<int, int> factors(int n)
{
    map<int, int> m;
    int d = 2;
    while (n > 1)
    {
        if (n % d == 0)
        {
            n /= d;
            m[d]++;
        }
        else
        {
            d++;
        }
    }

    return m;
}

int main()
{
    int limit = 1000000;
    vector<double> arr;
    long long cnt = 0;
    for (int i = 2; i <= limit; i++)
    {
        map<int, int> m = factors(i);
        // for (int k = 1; k <= i; k++)
        // {
        //     cout << k << ": " << m[k] << " ";
        // }
        // cout << endl;
        long long p = 1;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            for (int k = 0; k < it->second - 1; k++)
            {
                p *= it->first;
            }
            // cout << it->first - 1 << endl;
            p *= (it->first - 1);
        }
        cnt += p;
        if (i % 10000 == 0)
        {
            cout << i << " Proslo" << endl;
        }
    }

    cout << cnt << endl;
}