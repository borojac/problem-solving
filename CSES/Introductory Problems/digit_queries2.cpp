#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
    int q;
    cin >> q;
    vector<pair<ull, ull>> rngs;
    for (int i = 1; i <= 18; i++)
    {
        ull minn = (ull)pow(10, i - 1);
        ull maxx = (ull)pow(10, i) - 1;
        if (i == 1)
        {
            rngs.push_back(make_pair(1, 9));
            continue;
        }
        ull fr = rngs[rngs.size() - 1].second + 1;
        ull sc = (maxx - minn + 1) * i + fr - 1;
        rngs.push_back(make_pair(fr, sc));
    }

    for (int t = 0; t < q; t++)
    {
        ull k;
        cin >> k;
        if (k < 10)
        {
            cout << k << endl;
            continue;
        }
        int ii = 1;
        while (rngs[ii - 1].second < k)
        {
            ii++;
        }

        ull rb = k - rngs[ii - 1].first + 1;
        ull rbInt = rb / ii;
        ull minn = pow(10, ii - 1);
        ull targetNum = minn + rbInt - 1;

        targetNum++;

        int digit = rb % ii;
        if (digit == 0)
        {
            cout << (targetNum - 1) % 10 << endl;
        }
        else
        {
            string n = to_string(targetNum);
            cout << n[digit - 1] << endl;
        }
    }

    return 0;
}