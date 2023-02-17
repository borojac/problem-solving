#include <bits/stdc++.h>
#include <chrono>

using namespace std::chrono;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    vector<vector<long long>> mat;

    int limit = 80;
    for (int i = 0; i < limit; i++)
    {
        mat.push_back(vector<long long>());
        for (int j = 0; j < limit; j++)
        {
            long long x;
            cin >> x;
            mat[i].push_back(x);
        }
    }
    vector<vector<long long>> val(limit, vector<long long>(limit, 0));
    vector<vector<bool>> visited(limit, vector<bool>(limit, false));

    int ii = 0, jj = 0;

    deque<pair<int, int>> examine;
    visited[ii][jj] = true;
    val[ii][jj] = mat[ii][jj];
    examine.push_back(make_pair(ii, jj));

    while (!examine.empty())
    {
        pair<int, int> curr = examine.front();
        ii = curr.first;
        jj = curr.second;
        examine.pop_front();

        bool up = false, down = false, right = false, left = false;
        up = (ii - 1) >= 0;
        down = (ii + 1) < limit;
        right = (jj + 1) < limit;
        left = (jj - 1) >= 0;
        if (up)
        {
            if (!visited[ii - 1][jj])
            {
                val[ii - 1][jj] = val[ii][jj] + mat[ii - 1][jj];
                visited[ii - 1][jj] = true;
                examine.push_back(make_pair(ii - 1, jj));
            }
            else
            {
                if (val[ii][jj] + mat[ii - 1][jj] < val[ii - 1][jj])
                {
                    val[ii - 1][jj] = val[ii][jj] + mat[ii - 1][jj];
                    examine.push_back(make_pair(ii - 1, jj));
                }
            }
        }
        if (down)
        {
            if (!visited[ii + 1][jj])
            {
                val[ii + 1][jj] = val[ii][jj] + mat[ii + 1][jj];
                visited[ii + 1][jj] = true;
                if (!(ii == limit - 1 && jj + 1 == limit - 1))
                {
                    examine.push_back(make_pair(ii + 1, jj));
                }
            }
            else
            {
                if (val[ii][jj] + mat[ii + 1][jj] < val[ii + 1][jj])
                {
                    val[ii + 1][jj] = val[ii][jj] + mat[ii + 1][jj];
                    if (!(ii == limit - 1 && jj + 1 == limit - 1))
                    {
                        examine.push_back(make_pair(ii + 1, jj));
                    }
                }
            }
        }
        if (right)
        {
            if (!visited[ii][jj + 1])
            {
                val[ii][jj + 1] = val[ii][jj] + mat[ii][jj + 1];
                visited[ii][jj + 1] = true;
                if (!(ii == limit - 1 && jj + 1 == limit - 1))
                {
                    examine.push_back(make_pair(ii, jj + 1));
                }
            }
            else
            {
                if (val[ii][jj] + mat[ii][jj + 1] < val[ii][jj + 1])
                {
                    val[ii][jj + 1] = val[ii][jj] + mat[ii][jj + 1];
                    if (!(ii == limit - 1 && jj + 1 == limit - 1))
                    {
                        examine.push_back(make_pair(ii, jj + 1));
                    }
                }
            }
        }
        if (left)
        {
            if (!visited[ii][jj - 1])
            {
                val[ii][jj - 1] = val[ii][jj] + mat[ii][jj - 1];
                visited[ii][jj - 1] = true;
                examine.push_back(make_pair(ii, jj - 1));
            }
            else
            {
                if (val[ii][jj] + mat[ii][jj - 1] < val[ii][jj - 1])
                {
                    val[ii][jj - 1] = val[ii][jj] + mat[ii][jj - 1];
                    examine.push_back(make_pair(ii, jj - 1));
                }
            }
        }
    }

    cout << val[limit - 1][limit - 1];
    return 0;
}