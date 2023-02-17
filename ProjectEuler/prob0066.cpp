#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long D = 2;
    long long limit = 200;
    for (; D <= limit; D++)
    {
        long long sq = (long long)sqrt(D);
        if (sq * sq == D)
        {
            continue;
        }
        long long y = 1;
        for (;; y++)
        {
            long long xSquared = D * y * y + 1;
            long long xSq = (long long)sqrt(xSquared);
            if (xSq * xSq == xSquared)
            {
                cout << "D= " << D << "   x= " << xSq << endl;
                break;
            }
        }
    }

    return 0;
}