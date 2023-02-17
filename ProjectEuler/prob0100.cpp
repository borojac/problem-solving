#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x = 500001;
    for (;; x++)
    {
        long long t = 2 * x * (x - 1);
        double z = (1 + sqrt(1 + 4 * (double)t)) / 2;
        long long zz = (long long)z;
        if (z * (z - 1) == t)
        {
            cout << zz * (zz - 1);
            break;
        }
    }

    return 0;
}