#include <bits/stdc++.h>

using namespace std;

vector<int> primes = {2};

bool isPrime(int n)
{
    for (int i = 0; i < primes.size() && primes[i] <= sqrt(n); i++)
    {
        if (n % primes[i] == 0)
            return false;
    }
    return true;
}

int main()
{
    int PRIMES_LIMIT = 100000000;

    for (int i = 3; i <= PRIMES_LIMIT; i += 2)
    {
        if (isPrime(i))
            primes.push_back(i);
    }

    // cout << primes.size() << endl;

    cout << "PRIMES DETECTED!" << endl;
    long long summ = 0;
    for (int i = 0; i < (int)primes.size(); i++)
    {
        if ((i + 1) % 10000 == 0)
        {
            cout << i << " completed" << endl;
        }
        int d = primes[i] - 1;
        if (d % 4 == 0)
            continue;

        if (!binary_search(primes.begin(), primes.end(), d / 2 + 2))
            continue;

        vector<int> fs;
        for (int x = 1; x <= sqrt(d); x++)
        {
            if (d % x == 0)
            {
                fs.push_back(x);
                fs.push_back(d / x);
            }
        }
        bool valja = true;

        for (auto f : fs)
        {
            if (!binary_search(primes.begin(), primes.end(), f + d / f))
            {
                valja = false;
                break;
            }
        }
        if (valja)
        {
            summ += d;
        }
    }
    cout << summ << endl;
    return 0;
}