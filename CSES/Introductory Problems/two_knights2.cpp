#include <bits/stdc++.h>

using namespace std;

long long calculateQueens(long long l)
{
    return ((2 * (2 * l * l - 7)) + (l - 4) * (l * l - 5)) + (2 * (2 * l * l - 9) + (l - 4) * (l * l - 7)) + ((l - 4) * (2 * (2 * l * l - 12) + (l - 4) * (l * l - 9))) / 2;
    // for (int i = 0; i < l; i++)
    // {
    //     if (i == 0 || i == l - 1)
    //     {
    //         cnt += 2 * (l * l - 3);
    //         cnt += 2 * (l * l - 4);
    //         cnt += (l - 4) * (l * l - 5);
    //     }
    //     else if (i == 1 || i == l - 2)
    //     {
    //         cnt += 2 * (l * l - 4);
    //         cnt += 2 * (l * l - 5);
    //         cnt += (l - 4) * (l * l - 7);
    //     }
    //     else
    //     {
    //         cnt += 2 * (l * l - 5);
    //         cnt += 2 * (l * l - 7);
    //         cnt += (l - 4) * (l * l - 9);
    //     }
    // }

    // return cnt / 2;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> ways(7);
    ways[1] = 0;
    ways[2] = 6;
    ways[3] = 28;
    ways[4] = 96;
    ways[5] = 252;
    ways[6] = 550;

    for (int i = 1; i <= n; i++)
    {
        if (i <= 6)
        {
            cout << ways[i] << endl;
            continue;
        }
        cout << calculateQueens(i) << endl;
    }

    return 0;
}