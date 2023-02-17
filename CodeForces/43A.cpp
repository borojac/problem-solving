#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    string a = "", b = "";
    int aa = 0, bb = 0;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        if (a == "")
        {
            a = t;
        }
        else if (b == "" || a != t)
        {
            b = t;
        }
        if (t == a)
        {
            aa++;
        }
        else if (t == b)
        {
            bb++;
        }
    }
    if (aa > bb)
    {
        cout << a;
    }
    else
    {
        cout << b;
    }

    return 0;
}