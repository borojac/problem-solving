#include <bits/stdc++.h>

using namespace std;

vector<long long> v3;
vector<long long> v4;
vector<long long> v5;
vector<long long> v6;
vector<long long> v7;
vector<long long> v8;

vector<vector<long long>> v;

long long
triangle(long long n)
{
    return (n * (n + 1)) / 2;
}

long long square(long long n)
{
    return n * n;
}

long long pentagonal(long long n)
{
    return (n * (3 * n - 1)) / 2;
}

long long hexagonal(long long n)
{
    return n * (2 * n - 1);
}

long long heptagonal(long long n)
{
    return (n * (5 * n - 3)) / 2;
}

long long octagonal(long long n)
{
    return n * (3 * n - 2);
}

bool isAny(long long num)
{
    for (auto vv : v)
    {
        if (find(vv.begin(), vv.end(), num) != vv.end())
        {
            return true;
        }
    }
    return false;
}

vector<long long> generateEight(long long num)
{
    vector<long long> res;
    res.push_back(num);
    for (int i = 0; i < 5; i++)
    {
        long long old = num;
        num = num % 100;
        num *= 100;
        num += (old / 100);
        // if (find(res.begin(), res.end(), num) != res.end())
        // return res;
        res.push_back(num);
    }
    return res;
}

void solve(vector<vector<bool>> &c, vector<bool> &cols, vector<long long> state, int rb)
{
    if (rb == 6)
    {
        if (state[0] / 100 == state[5] % 100)
        {
            long long summ = 0;
            for (long long u : state)
            {
                summ += u;
                cout << " " << u;
            }
            cout << "   " << summ;
            cout << endl;
        }
        return;
    }

    for (int i = 0; i < 6; i++)
    {
        if (cols[i])
            continue;

        cols[i] = true;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (rb == 0)
            {
                state.push_back(v[i][j]);
                c[i][j] = true;
                solve(c, cols, state, rb + 1);
                c[i][j] = false;
                state.pop_back();
            }
            else
            {
                long long back = state.back();
                if (v[i][j] / 100 == (back % 100))
                {
                    c[i][j] = true;
                    state.push_back(v[i][j]);
                    solve(c, cols, state, rb + 1);
                    state.pop_back();
                    c[i][j] = false;
                }
            }
        }
        cols[i] = false;
    }
}

int main()
{
    int n = 1;
    while (true)
    {
        long long res = triangle(n);
        if (res > 9999)
            break;
        if (res > 999)
        {
            if (((res / 10) % 10) == 0)
            {
                n++;
                continue;
            };
            v3.push_back(res);
        }
        n++;
    }
    n = 1;
    while (true)
    {
        long long res = square(n);
        if (res > 9999)
            break;
        if (res > 999)
        {
            if (((res / 10) % 10) == 0)
            {
                n++;
                continue;
            };
            v4.push_back(res);
        }
        n++;
    }
    n = 1;
    while (true)
    {
        long long res = pentagonal(n);
        if (res > 9999)
            break;
        if (res > 999)
        {
            if (((res / 10) % 10) == 0)
            {
                n++;
                continue;
            };
            v5.push_back(res);
        }
        n++;
    }
    n = 1;
    while (true)
    {
        long long res = hexagonal(n);
        if (res > 9999)
            break;
        if (res > 999)
        {
            if (((res / 10) % 10) == 0)
            {
                n++;
                continue;
            };
            v6.push_back(res);
        }
        n++;
    }
    n = 1;
    while (true)
    {
        long long res = heptagonal(n);
        if (res > 9999)
            break;
        if (res > 999)
        {
            if (((res / 10) % 10) == 0)
            {
                n++;
                continue;
            };
            v7.push_back(res);
        }
        n++;
    }
    n = 1;
    while (true)
    {
        long long res = octagonal(n);
        if (res > 9999)
            break;
        if (res > 999)
        {
            if (((res / 10) % 10) == 0)
            {
                n++;
                continue;
            };
            v8.push_back(res);
        }
        n++;
    }
    v = {v3, v4, v5, v6, v7, v8};
    vector<vector<bool>> c(100, vector<bool>(100, false));
    vector<bool> cols(6, false);
    vector<long long> state;
    solve(c, cols, state, 0);

    return 0;
}