#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> t;
    for (int i = 0; i < n; i++)
    {
        t.push_back(i + 1);
    }
    int beg = 1;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    while (!t.empty())
    {
        cout << t[beg] << " ";
        t.erase(t.begin() + beg);
        if (t.size() == 0)
        {
            break;
        }
        beg %= t.size();
        beg++;
        beg %= t.size();
    }
    cout << endl;
    return 0;
}