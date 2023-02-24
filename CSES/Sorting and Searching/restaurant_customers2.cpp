#include <bits/stdc++.h>

using namespace std;

bool ccc(pair<long long, long long> a, pair<long long, long long> b)
{
    return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;

    // vector<pair<long long, long long>> arr;
    vector<long long> aa;
    vector<long long> bb;

    for (int i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;
        aa.push_back(a);
        bb.push_back(b);
        // arr.push_back(make_pair(a, b));
    }

    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());

    int i1 = 0, i2 = 0;
    long long cnt = 0;
    long long maxx = 0;
    while (true)
    {
        if (i1 == aa.size())
        {
            break;
        }
        if (i2 == bb.size())
        {
            i1++;
            cnt++;
            maxx = max(cnt, maxx);
            continue;
        }
        if (aa[i1] < bb[i2])
        {
            i1++;
            cnt++;
            maxx = max(cnt, maxx);
            continue;
        }
        if (bb[i2] < aa[i1])
        {
            i2++;
            cnt--;
            maxx = max(cnt, maxx);
            continue;
        }
    }
    cout << maxx << endl;

    return 0;
}