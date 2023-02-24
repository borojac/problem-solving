#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s.size() % 2 == 0)
        {
            // reverse(s.begin(), s.begin() + s.size() / 2);
            // cout << s << endl;
            if (s.substr(0, s.size() / 2) == s.substr(s.size() / 2, s.size() / 2))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}