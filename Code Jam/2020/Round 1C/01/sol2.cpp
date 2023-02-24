#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("codejam1c/01/input.txt", "r", stdin);
    freopen("codejam1c/01/output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt ++) {
        int x0 = 0, y0 = 0;
        int x, y;
        cin >> x >> y;
        string ppath;
        cin >> ppath;
        vector<pair<int, int>> pos;
        pos.push_back(make_pair(x, y));
        for (char p : ppath) {
            if (p == 'N')
                y += 1;
            else if (p == 'S') {
                y -= 1;
            } else if (p == 'E') {
                x += 1;
            } else {
                x -= 1;
            }
            pos.push_back(make_pair(x, y));
        }
        bool found = false;
        for (int i = 0; i < pos.size(); i ++) {
            auto c = pos[i];
            int dist = abs(pos[i].first - x0) + abs(pos[i].second - y0);
            if (i >= dist) {
                cout << "Case #" << tt + 1 << ": " << i << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Case #" << tt + 1 << ": IMPOSSIBLE" << endl;
        }
    }
}