#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int k = 0; k < t; k++)
    {
        string a, s;
        cin >> a;
        cin >> s;
        int as = a.size(), ss = s.size();
        int ia = 1, is = 1;
        string res = "";
        bool flag = false;
        while (is <= s.size() && ia <= a.size())
        {
            if (s[ss - is] >= a[as - ia])
            {
                res += '0' + s[ss - is] - a[as - ia];
                is += 1;
            }
            else
            {
                if (ss - is - 1 >= 0 && s[ss - is - 1] != '1')
                {
                    cout << -1 << endl;
                    flag = true;
                    break;
                }
                int sss = 10 + s[ss - is] - '0';
                int aaa = a[as - ia] - '0';
                res += (sss - aaa) + '0';
                is += 2;
                if (is - 1 > s.size())
                {
                    cout << -1 << endl;
                    flag = true;
                    break;
                }
            }
            ia += 1;
        }
        if (flag)
            continue;
        if (ia <= a.size())
        {
            cout << -1 << endl;
            continue;
        }
        while (is <= s.size())
        {
            res += s[ss - is];
            is++;
        }
        reverse(res.begin(), res.end());
        if (res[0] == '0' && res.size() > 1)
        {
            int ii = 0;
            while (ii < res.size() && res[ii] == '0')
                ii++;
            if (ii == res.size())
                cout << 0 << endl;
            else
            {
                for (int i = ii; i < res.size(); i++)
                {
                    cout << res[i];
                }
                cout << endl;
            }
            // cout << res.substr(1, s.size() - 1) << endl;
        }
        else
        {
            cout << res << endl;
        }
    }

    return 0;
}