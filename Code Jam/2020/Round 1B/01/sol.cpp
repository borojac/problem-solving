#include <bits/stdc++.h>

using namespace std;

bool solved = false;
int cnt = INT_MAX;
int limit = 0;
string result ;

int solve(int sx, int sy, int x, int y, int value, string res)
{
    if (sx == x && sy == y)
    {
        if (cnt > res.size()){
            cnt = res.size();
            result = res;
        }
        solved = true;
        return 1;
    }
    if (value > limit)
        return INT_MAX;

    solve(sx + value, sy, x, y, value * 2, res + "E"); 
    solve(sx - value, sy, x, y, value * 2, res + "W");
    solve(sx, sy + value, x, y, value * 2, res + "N");
    solve(sx, sy - value, x, y, value * 2, res + "S");
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("Round1b\\01\\input.txt", "r", stdin);
    freopen("Round1b\\01\\output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        solved = false;
        limit = 1 << 10;
        cnt = INT_MAX;
        result = "";
        solve(0, 0, x, y, 1, "");
        if (solved)
            cout << "Case #" << i + 1 << ": " << result;
        else
            cout << "Case #" << i + 1 << ": IMPOSSIBLE";
        
        if (i != t - 1)
            cout << endl;
    }
}