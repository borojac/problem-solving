#include <bits/stdc++.h>

using namespace std;

long long bc(long long n, long long k)
{
    long long C[n + 1][k + 1];
    long long i, j;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long summ = 0;
    for (int i = 49; i >= 25; i--)
    {
        cout << i << " " << i - (50 - i) << endl;
        summ += bc(i, i - (50 - i));
    }
    cout << endl
         << endl;
    for (int i = 0; i < 16; i++)
    {
        cout << 48 - i * 2 << " " << 47 - i * 3 << endl;
        summ += bc(48 - i * 2, 47 - i * 3);
    }

    cout << endl
         << endl;

    for (int i = 0; i < 12; i++)
    {
        cout << 47 - i * 3 << " " << 46 - i * 4 << endl;
        summ += bc(47 - i * 3, 46 - i * 4);
    }

    cout << summ << endl;
    return 0;
}