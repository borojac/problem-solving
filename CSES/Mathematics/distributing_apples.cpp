#include <bits/stdc++.h>

using namespace std;
long long MODULL = 1e9 + 7;

long long generateN_OVER_K(long long n, long long k)
{
    vector<long long> M;
    M.push_back(1);
    for (int i = 1; i <= n; i++)
    {
        vector<long long> tmp;
        tmp.push_back(1);
        for (int j = 1; j < M.size(); j++)
        {
            tmp.push_back((M[j - 1] + M[j]) % MODULL);
        }
        tmp.push_back(1);
        M = tmp;
    }
    return M[k];
}

long long kf;
long long nkf;

long long fact(long long n, long long k)
{
    long long res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
        res %= MODULL;
        if (i == k)
        {
            kf = res;
        }
        if (i == n - k)
        {
            nkf = res;
        }
    }
    if (k == 1 || k == 0)
    {
        kf = 1;
    }
    if (n - k == 1 || n - k == 0)
    {
        nkf = 1;
    }

    return res;
}

long long expp(long long a, long long b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 0)
    {
        return ((expp(a, b / 2) % MODULL) * (expp(a, b / 2) % MODULL)) % MODULL;
    }
    else
    {
        return (a * (expp(a, b - 1)) % MODULL) % MODULL;
    }
}

int main()
{
    long long n, m;
    cin >> n >> m;

    long long N = n + m - 1;
    long long K = n - 1;

    long long nf = fact(N, K);
    long long mf = (kf * nkf) % MODULL;

    long long mfi = expp(mf, MODULL - 2) % MODULL;

    cout << (((nf) * (mfi)) % MODULL) << endl;

    return 0;
}