#include <bits/stdc++.h>

using namespace std;

double len(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double diff(double l1, double l2, double l3)
{
    return abs(l3 * l3 - l1 * l1 - l2 * l2);
}

int main()
{
    int LIMIT = 50;
    double error = 1e-8;
    int cnt = 0;
    for (int x1 = 0; x1 <= LIMIT; x1++)
    {
        for (int y1 = 0; y1 <= LIMIT; y1++)
        {
            if (x1 == 0 && y1 == 0)
                continue;
            for (int x2 = 0; x2 <= LIMIT; x2++)
            {
                for (int y2 = 0; y2 <= LIMIT; y2++)
                {
                    if (x2 == 0 && y2 == 0)
                        continue;
                    if (x1 == x2 && y1 == y2)
                        continue;
                    double l1 = len(x1, y1, x2, y2);
                    double l2 = len(0, 0, x1, y1);
                    double l3 = len(0, 0, x2, y2);

                    if (diff(l1, l2, l3) < error || diff(l1, l3, l2) < error || diff(l2, l3, l1) < error)
                    {
                        cout << "(" << x1 << ", " << y1 << ") (" << x2 << ", " << y2 << ")" << endl;
                        cnt++;
                    }
                }
            }
        }
    }

    cout << cnt / 2 << endl;

    return 0;
}