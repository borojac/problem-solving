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
    long long minn = LONG_LONG_MAX;
    for (int t = 0; t < limit; t++)
    {
        vector<vector<long long>> val(limit, vector<long long>(limit, 0));
        vector<vector<bool>> visited(limit, vector<bool>(limit, false));

        int ii = t, jj = 0;

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

            bool up = false, down = false, right = false;
            up = (ii - 1) >= 0;
            down = (ii + 1) < limit;
            right = (jj + 1) < limit;
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
                    examine.push_back(make_pair(ii + 1, jj));
                }
                else
                {
                    if (val[ii][jj] + mat[ii + 1][jj] < val[ii + 1][jj])
                    {
                        val[ii + 1][jj] = val[ii][jj] + mat[ii + 1][jj];
                        examine.push_back(make_pair(ii + 1, jj));
                    }
                }
            }
            if (right)
            {
                if (!visited[ii][jj + 1])
                {
                    val[ii][jj + 1] = val[ii][jj] + mat[ii][jj + 1];
                    visited[ii][jj + 1] = true;
                    if (jj + 1 < limit - 1)
                    {
                        examine.push_back(make_pair(ii, jj + 1));
                    }
                }
                else
                {
                    if (val[ii][jj] + mat[ii][jj + 1] < val[ii][jj + 1])
                    {
                        val[ii][jj + 1] = val[ii][jj] + mat[ii][jj + 1];
                        if (jj < limit - 1)
                        {
                            examine.push_back(make_pair(ii, jj + 1));
                        }
                    }
                }
            }
        }

        for (int i = 0; i < limit; i++)
        {
            if (val[i][limit - 1] < minn)
            {
                minn = val[i][limit - 1];
            }
        }
    }
    cout << minn;
    return 0;
}