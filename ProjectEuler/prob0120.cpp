#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long summ = 0;
    for (int i = 3; i <= 1000; i++)
    {
        long long a = i;
        long long maxx = -1001;

        for (int n = 1; n < 1000; n++)
        {
            long long m = (2 * n * a) % (a * a);

            if (m > maxx)
            {
                maxx = m;
            }
        }
        summ += maxx;
    }
    cout << summ << endl;
    return 0;
}