#include <bits/stdc++.h>

using namespace std;

long long cnt;

long long countt(long long x, long long parts)
{
    long long im = 1;
    for (int i = 1; i <= x + parts - 1; i++)
        im *= i;
    long long br1 = 1;
    long long br2 = 1;
    for (int i = 1; i <= parts - 1; i++)
        br1 *= i;
    for (int i = 1; i <= x; i++)
        br2 *= i;

    return im / (br1 * br2);
}

int main()
{
    cnt = 0;

    long long n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cnt += countt(n, i);
    }

    cout << cnt;
    return 0;
}