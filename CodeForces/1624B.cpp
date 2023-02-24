#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        long long a, b, c, m;
        cin >> a >> b >> c;
        if (a == b && b == c)
        {
            cout << "YES" << endl;
            continue;
        }
        // if a
        long long d = c - b;
        if (a != 0 && a != 0)
        {
            long long m = (b - d) / a;
            if (m > 0 && m * a == b - d)
            {
                cout << "YES" << endl;
                continue;
            }
        }
        // if b
        d = (c - a) / 2;
        if (b != 0 && (c - a) % 2 == 0)
        {
            long long m = (a + d) / b;
            if (m > 0 && m * b == a + d)
            {
                cout << "YES" << endl;
                continue;
            }
        }

        // if c
        d = b - a;
        if (c != 0)
        {
            long long m = (b + d) / c;
            if (m > 0 && m * c == b + d)
            {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }

    return 0;
}