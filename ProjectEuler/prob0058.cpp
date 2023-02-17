#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long num)
{
    if (num == 1)
        return false;
    if (num == 2)
        return true;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> odd;
    odd.push_back(1);

    long long dl, dg;
    dl = 2;
    dg = 4;
    long long beg = 3;
    int cnt = 0;
    int pr = 0;
    while (true)
    {
        for (int i = 0; i < 4; i++)
        {
            odd.push_back(beg);
            if (isPrime(beg))
            {
                pr++;
            }
            beg += dl;
        }
        beg -= dl;
        beg += dg;
        dl += 2;
        dg += 2;
        // cnt++;
        if ((double)pr / odd.size() < 0.1)
        {
            break;
        }
    }

    cout << 1 + (odd.size() - 1) / 2;

    return 0;
}