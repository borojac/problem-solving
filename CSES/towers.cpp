#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    deque<long long> r;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        if (r.size() == 0)
        {
            r.push_back(x);
        }
        else
        {
            int index = upper_bound(r.begin(), r.end(), x) - r.begin();
            if (index >= 0 && index < r.size())
            {
                r[index] = x;
            }
            else
            {
                if (r[0] > x)
                {
                    r.push_front(x);
                }
                else
                {
                    r.push_back(x);
                }
                // r.push_back(x);
            }
        }
        // sort(r.begin(), r.end());
    }

    cout << r.size();

    return 0;
}