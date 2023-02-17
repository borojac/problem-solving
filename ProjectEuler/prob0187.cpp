#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

bool isPrime(int num)
{
    for (int i : primes)
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

    int limit = 5 * 10000000;

    primes.push_back(2);
    for (int i = 3; i <= limit; i += 2)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }

    // for (int i = 0; i < primes.size(); i++)
    // {
    //     cout << primes[i] << " ";
    // }

    return 0;
}