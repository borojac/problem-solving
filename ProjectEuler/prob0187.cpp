#include <bits/stdc++.h>

using namespace std;

vector<long long> primes;

bool isPrime(long long n)
{
    for (auto i : primes)
    {
        if (i > sqrt(n))
            break;
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    auto start = chrono::steady_clock::now();

    // do some stuff here

    long long LIMIT = 100000000;
    primes.push_back(2);
    for (long long i = 3; i < LIMIT; i += 2)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }

    auto end = chrono::steady_clock::now();
    cout << primes.size();
    cout << endl
         << "Elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;

    start = chrono::steady_clock::now();

    int i1 = 0, i2 = primes.size() - 1;
    long long cnt = 0;

    for (; i2 >= 0; i2--)
    {
        i1 = 0;
        while (i1 <= i2 && primes[i1++] * primes[i2] < LIMIT)
            cnt++;
    }

    end = chrono::steady_clock::now();
    cout << cnt << endl;
    cout
        << "Elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;
    return 0;
}