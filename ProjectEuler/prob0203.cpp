#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    if (n == 2)
    {
        return true;
    }
    if (n == 3)
    {
        return true;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long LIMIT = 2000;
    vector<int> primes;
    for (int i = 2; i <= LIMIT; i++)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }
    long long C[51][51];
    C[0][0] = 1;
    for (int i = 0; i < 51; i++)
    {
        for (int j = 0; j < 51; j++)
        {
            C[i][j] = 0;
        }
    }
    for (int i = 1; i < 51; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0)
            {
                C[i][j] = 1;
            }
            else if (j == i)
            {
                C[i][j] = 1;
            }
            else
            {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            }
        }
    }

    set<long long> s;
    for (int i = 0; i < 51; i++)
    {
        for (int j = 0; j < 51; j++)
        {
            long long x = C[i][j];
            if (x != 0)
            {
                bool found = false;
                for (int xx : primes)
                {
                    if (xx * xx <= x && x % (xx * xx) == 0)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    s.insert(C[i][j]);
                }
            }
        }
    }

    long long res = 0;

    for (auto it = s.begin(); it != s.end(); ++it)
    {
        res += *it;
    }

    cout << res << endl;

    return 0;
}