#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<bitset<30>> s;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        s.push_back(bitset<30>(t));
    }
    int minn = 31;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            auto res = s[i] ^ s[j];
            if (res.count() < minn)
            {
                minn = res.count();
            }
        }
    }

    cout << minn;
    return 0;
}