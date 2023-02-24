#include <bits/stdc++.h>

using namespace std;

int DIM = 15;
int maxx = 0;
vector<int> opt;

void solve(vector<vector<int>> &mat, vector<bool> &visitedR, vector<bool> &visitedC, int summ, int rb)
{
    if (opt[DIM - 1 - rb] + summ < maxx)
    {
        return;
    }
    if (rb == DIM)
    {
        if (maxx < summ)
        {
            maxx = summ;
        }
        return;
    }

    // for (int i = 0; i < DIM; i++)
    // {

    // if (visitedR[i])
    // continue;
    // if (opt[DIM - 1 - rb] + summ < maxx)
    // {
    //     break;
    // }
    // visitedR[i] = true;
    for (int j = 0; j < DIM; j++)
    {

        if (visitedC[j])
            continue;
        visitedC[j] = true;
        summ += mat[rb][j];
        solve(mat, visitedR, visitedC, summ, rb + 1);
        visitedC[j] = false;
        summ -= mat[rb][j];
    }
    // visitedR[i] = false;
    // }
}

int main()
{
    freopen("input.txt", "r", stdin);

    vector<vector<int>> mat(DIM, vector<int>(DIM));
    for (int i = 0; i < DIM; i++)
    {
        int mm = 0;
        for (int j = 0; j < DIM; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] > mm)
            {
                mm = mat[i][j];
            }
        }
        opt.push_back(mm);
    }

    reverse(opt.begin(), opt.end());
    for (int i = 0; i < (int)opt.size(); i++)
    {
        if (i != 0)
        {
            opt[i] += opt[i - 1];
        }
    }
    vector<bool> visited(DIM, false);
    vector<bool> visitedC(DIM, false);
    vector<int> state;
    int summ = 0;
    solve(mat, visited, visitedC, summ, 0);

    cout << maxx;
    return 0;
}