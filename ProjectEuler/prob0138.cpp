#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long l = 11;

    vector<long long> res;
    res.push_back(17);
    res.push_back(305);

    for (int i = 0; i < 10; i++)
    {
        res.push_back(18 * res.back() - res[res.size() - 2]);
    }

    long long s = 0;
    s = accumulate(res.begin(), res.end(), s);
    cout << s << endl;
    return 0;
}