#include <bits/stdc++.h>

using namespace std;
map<int, int> pmap;
map<int, int> cmap;

long long cnt = 0;
void solve(vector<int> &cs, int target, int step, int targetSteps)
{
    if (step == targetSteps)
    {
        if (target == 0)
        {
            cnt++;
        }
        return;
    }

    for (int i = 0; i < cs.size(); i++)
    {
        solve(cs, target - cs[i], step + 1, targetSteps);
    }
}

long long countWays(vector<int> cs, int target)
{
    cnt = 0;
    int steps = (cs.size() == 4) ? 9 : 6;
    solve(cs, target, 0, steps);
    return cnt;
}

int main()
{
    vector<int> p = {1, 2, 3, 4};
    vector<int> c = {1, 2, 3, 4, 5, 6};

    double cntp = pow(4, 9);
    double cntc = pow(6, 6);

    double x = 0;

    for (int i = 9; i <= 36; i++)
    {
        double px = (double)countWays(p, i) / cntp;
        double cx = 0;
        for (int j = 6; j < i; j++)
        {
            double ccx = (double)countWays(c, j) / cntc;
            cx += ccx;
        }
        x += cx * px;
    }
    cout << setprecision(7) << x;
    return 0; // 0.5731441
}