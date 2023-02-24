#include <bits/stdc++.h>

using namespace std;

vector<int> primes = {2};
unordered_map<int, bool> mp;

bool isPrime(int n)
{
    for (int i = 0; i < primes.size() && primes[i] <= sqrt(n); i++)
    {
        if (n % primes[i] == 0)
            return false;
    }
    mp[n] = true;
    return true;
}

void factors(int n, map<int, int> &m, bool add)
{
    // int d = 2;
    int index = 0;
    while (n > 1)
    {
        if (mp[n])
        {
            if (add)
            {
                m[n]++;
                break;
            }
            else
            {
                m[n]--;
                break;
            }
        }
        if (n % primes[index] == 0)
        {
            n /= primes[index];
            if (add)
                m[primes[index]]++;
            else
                m[primes[index]]--;
        }
        else
        {
            index++;
        }
    }
}

int main()
{
    mp[2] = true;

    int PRIMES_LIMIT = 20000000;

    for (int i = 3; i <= PRIMES_LIMIT; i += 2)
    {
        if (isPrime(i))
            primes.push_back(i);
    }
    cout << "GENERISANI PROSTI BROJEVI" << endl;
    map<int, int> m;
    for (int i = 2; i <= 5000000; i++)
    {

        if (mp[i])
        {
            m[i]--;
        }
        else
        {
            factors(i, m, false);
        }
    }

    cout << "ZAVRSENI DOLJE" << endl;

    for (int i = 15000001; i <= 20000000; i++)
    {

        if (mp[i])
        {
            m[i]++;
        }
        else
        {
            factors(i, m, true);
        }
    }

    cout << "ZAVRSENI GORE" << endl;
    long long summ = 0;
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        summ += it->first * it->second;
    }

    cout << summ << endl;

    return 0;
}