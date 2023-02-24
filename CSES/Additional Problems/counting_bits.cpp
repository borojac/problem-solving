#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;
    unsigned long long bitCnt = log(n) / log(2);

    unsigned long long cnt = 0;
    cnt += bitCnt * (unsigned long long)pow(2, bitCnt - 1);

    unsigned long long left = n - (unsigned long long)(pow(2, bitCnt));
    cnt += left + 1;
    string ls = bitset<64>(left).to_string();

    for (int i = 0; i < 64; i++)
    {
        if (i == 63 && ls[i] == '1')
        {
            cnt++;
            continue;
        }
        if (ls[i] == '1')
        {
            unsigned long long rb = 64 - i - 1;
            if (i + 1 < 64)
            {
                string tmp = ls.substr(i + 1);
                unsigned long long x = stoull(tmp, nullptr, 2);
                cnt += x + 1;
            }
            cnt += rb * (unsigned long long)pow(2, rb - 1);
        }
    }

    cout << cnt;

    return 0;
}