#include <bits/stdc++.h>
#include <chrono>

using namespace std::chrono;
using namespace std;

vector<long long> primes;

bool isPrime(int n)
{
    for (int i = 0; i < (int)primes.size() && primes[i] <= sqrt(n); i++)
    {
        if (n % primes[i] == 0)
        {
            return false;
        }
    }
    return true;
}

bool isPrime2(long long n)
{
    for (long long i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool concat(int a, int b)
{
    long long aa = a * pow(10, 1 + (int)(log(b) / log(10))) + b;
    long long bb = b * pow(10, 1 + (int)(log(a) / log(10))) + a;
    // cout << pow(10, 1 + (int)(log(b) / log(10))) << " " << a << " " << b << " " << aa << " " << bb << endl;
    if (isPrime2(aa) && isPrime2(bb))
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    primes.push_back(2);

    for (int i = 3; i < 15000; i += 2)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }

    for (int i = 1; i < primes.size() - 4; i++)
    {
        for (int j = i; j < primes.size() - 3; j++)
        {
            if (concat(primes[i], primes[j]))
            {
                for (int k = j; k < primes.size() - 2; k++)
                {
                    if (concat(primes[i], primes[k]) && concat(primes[j], primes[k]))
                    {
                        for (int t = k; t < primes.size() - 1; t++)
                        {
                            if (concat(primes[i], primes[t]) && concat(primes[j], primes[t]) && concat(primes[k], primes[t]))
                            {
                                for (int l = t; l < primes.size(); l++)
                                {
                                    if (concat(primes[i], primes[l]) && concat(primes[j], primes[l]) && concat(primes[k], primes[l]) && concat(primes[t], primes[l]))
                                    {
                                        cout << primes[i] << " " << primes[j] << " " << primes[k] << " " << primes[t] << " " << primes[l];
                                        i = primes.size();
                                        j = primes.size();
                                        k = primes.size();
                                        t = primes.size();
                                        l = primes.size();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // vector<pair<int, int>> step1;
    // auto start = high_resolution_clock::now();
    // for (int i = 1; i < (int)primes.size() - 1; i++)
    // {
    //     for (int j = i + 1; j < (int)primes.size(); j++)
    //     {
    //         if (concat(primes[i], primes[j]))
    //         {
    //             step1.push_back(make_pair(primes[i], primes[j]));
    //         }
    //     }
    // }
    // auto stop = high_resolution_clock::now();
    // cout << "Vrijeme: " << duration_cast<milliseconds>(stop - start).count() << endl;
    // cout << "Parova ima: " << step1.size() << endl
    //      << endl;

    // start = high_resolution_clock::now();

    // map<int, vector<int>> mp;
    // set<int> s;
    // int maxx = 0;
    // int overFour = 0;
    // int summ = 0;
    // for (int i = 0; i < (int)step1.size(); i++)
    // {
    //     s.insert(step1[i].first);
    //     s.insert(step1[i].second);
    //     mp[step1[i].first].push_back(step1[i].second);
    //     mp[step1[i].second].push_back(step1[i].first);
    //     if (maxx < mp[step1[i].first].size())
    //     {
    //         maxx = mp[step1[i].first].size();
    //     }
    //     if (maxx < mp[step1[i].second].size())
    //     {
    //         maxx = mp[step1[i].second].size();
    //     }
    // }
    // auto it = s.begin();
    // while (it != s.end())
    // {
    //     if (mp[*it].size() > 4)
    //     {
    //         overFour++;
    //     }
    //     summ += mp[*it].size();
    //     it++;
    // }

    // stop = high_resolution_clock::now();

    // cout << "Vrijeme: " << duration_cast<milliseconds>(stop - start).count() << endl;
    // cout << "Velicina mape: " << mp.size() << endl;
    // cout << "Najvise veza: " << maxx << endl;
    // cout << "Odgovarajucih ima: " << overFour << endl;
    // cout << "Suma svih: " << summ << endl
    //      << endl;
    return 0;
}