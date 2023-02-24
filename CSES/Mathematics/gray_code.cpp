#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < (int)pow(2, n); i++)
    {
        bitset<16> tmp(i);
        string t = tmp.to_string().substr(16 - n);
        for (int ii = t.size() - 1; ii >= 1; ii--)
        {
            if (t[ii - 1] == '1')
            {
                t[ii] = (t[ii] == '0') ? '1' : '0';
            }
        }
        cout << t << endl;
    }

    return 0;
}