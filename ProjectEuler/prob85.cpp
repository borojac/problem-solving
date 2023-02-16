#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long minDiff = 100000000;
    long long area = -1;
    long long lim = 2000000;
    for (long long a = 1; a <= 10000; a++)
    {
        for (long long b = 1; b <= 10000; b++)
        {
            if (abs((a * (a + 1) * b * (b + 1)) / 4 - lim) < minDiff)
            {
                minDiff = abs((a * (a + 1) * b * (b + 1)) / 4 - lim);
                area = a * b;
            }
        }
    }

    cout << "Diff: " << minDiff << endl;
    cout << "Area: " << area << endl;
    return 0;
}