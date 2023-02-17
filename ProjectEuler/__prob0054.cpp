#include <bits/stdc++.h>

using namespace std;

class Card {
   public:
    int num;
    char sign;
};

vector<int> cl;

int evaluate(vector<Card> h) {
    cl.clear();
    vector<int> hist(16, 0);
    vector<int> vals;
    set<char> ff;
    for (Card c : h) {
        hist[c.num]++;
        ff.insert(c.sign);
        vals.push_back(c.num);
    }

    for (int i = 0; i < 16; i++)
        if (hist[i] == 4)
            return 8000 + i * 10;

    bool has3 = false, has2 = false, has22 = false;
    int c3, c2, c22;
    for (int i = 0; i < 16; i++) {
        if (hist[i] == 3) {
            has3 = true;
            c3 = i;
        }
        if (hist[i] == 2) {
            if (!has2) {
                has2 = true;
                c2 = i;
            } else {
                has22 = true;
                c22 = i;
            }
        }
    }

    if (has3 && has2) {
        return 7000 + c3 * 30 + c2;
    }

    if (has3) {
        return 4000 + c3 * 10;
    }

    if (has2 && has22) {
        for (int v : vals) {
            if (v != max(c2, c22)) cl.push_back(v);
        }
        return 3000 + max(c2, c22) * 10;
    }

    if (has2) {
        for (int v : vals) {
            if (v != c2) cl.push_back(v);
        }
        return 2000 + c2 * 10;
    }

    bool isFlush = false;
    if (ff.size() == 1) isFlush = true;

    sort(vals.begin(), vals.end());

    bool first4 = true;
    for (int i = 1; i < 4; i++) {
        if (vals[i] - vals[i - 1] != 1) first4 = false;
    }
    bool isStraight = false;
    if (first4 && vals.back() == 16 && vals[0] == 2) isStraight = true;
    if (first4 && vals.back() - vals[3] == 1) isStraight = true;

    if (isStraight && isFlush && vals.back() == 16 && vals[3] == 14) return 10000;

    if (isStraight && isFlush) {
        int tmpv = vals.back() == 16 ? vals[3] : vals.back();
        return 9000 + tmpv * 10;
    }

    if (isFlush) {
        for (int v : vals) {
            cl.push_back(v);
        }
        return 6000 + vals.back() * 10;
    }

    if (isStraight) {
        return 5000 + vals.back() * 10;
    }
    for (int v : vals) {
        cl.push_back(v);
    }
    return *max_element(vals.begin(), vals.end());
}

int main() {
    freopen("input_prob54.txt", "r", stdin);
    string s;
    vector<vector<Card>> a, b;
    map<char, int> mp = {
        {'A', 15},
        {'T', 10},
        {'K', 14},
        {'Q', 13},
        {'J', 12}};

    while (cin >> s) {
        vector<string> tmp1 = {s};
        vector<string> tmp2;
        for (int i = 0; i < 4; i++) {
            cin >> s;
            tmp1.push_back(s);
        }
        for (int i = 0; i < 5; i++) {
            cin >> s;
            tmp2.push_back(s);
        }
        vector<Card> h1, h2;
        for (int i = 0; i < 5; i++) {
            // cout << tmp1[i] << " " << tmp2[i] << endl;
            int x1, x2;
            if (isdigit(tmp1[i][0])) {
                x1 = tmp1[i][0] - '0';
            } else {
                x1 = mp[tmp1[i][0]];
            }
            if (isdigit(tmp2[i][0])) {
                x2 = tmp2[i][0] - '0';
            } else {
                x2 = mp[tmp2[i][0]];
            }
            char s1 = tmp1[i][1];
            char s2 = tmp2[i][1];
            // cout << x1 << " " << s1 << " " << x2 << " " << s2 << endl;
            h1.push_back({x1, s1});
            h2.push_back({x2, s2});
        }
        a.push_back(h1);
        b.push_back(h2);
    }

    // Start duels
    int p1 = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        int ea = evaluate(a[i]);
        vector<int> ca = cl;
        int eb = evaluate(b[i]);
        // cout << ea << " " << eb << endl;
        vector<int> cb = cl;
        if ((ea > 2000 && ea < 3000) && (eb > 2000 && eb < 3000)) {
            cout << ea << " " << eb << endl;
            for (int t = 0; t < a[i].size(); t++) {
                cout << a[i][t].num << " " << a[i][t].sign << " " << b[i][t].num << " " << b[i][t].sign << endl;
            }
            cout << endl;
        }
        // if (ea / 1000 == eb / 1000 && ea > 1000) {
        // cout << ea << " " << eb << " " << (ea == eb) << endl;
        // if (ea == eb) {
        // for (int t = 0; t < a[i].size(); t++) {
        //     cout << a[i][t].num << " " << a[i][t].sign << " " << b[i][t].num << " " << b[i][t].sign << endl;
        // }
        // }
        // }
        if (ea > eb) {
            p1++;
        } else if (ea == eb) {
            sort(ca.rbegin(), ca.rend());
            sort(cb.rbegin(), cb.rend());
            if (ea >= 3000 && ea < 4000) {
                vector<int> thista(16, 0), thistb(16, 0);
                int ca2, cb2;
                for (int ii = 0; ii < ca.size(); ii++) {
                    thista[ca[ii]]++;
                    thistb[cb[ii]]++;
                    if (thista[ca[ii]] == 2) ca2 = ca[ii];
                    if (thistb[cb[ii]] == 2) cb2 = cb[ii];
                }
                if (ca2 > cb2) {
                    p1++;
                    continue;
                } else if (ca2 < cb2) {
                    continue;
                }
                for (int ii = 0; ii < ca.size(); ii++) {
                    if (ca[ii] == ca2) ca[ii] = 10000;
                    if (cb[ii] == ca2) cb[ii] = 10000;
                }
            }
            for (int ii = 0; i < ca.size(); ii++) {
                if (ca[ii] > cb[ii]) {
                    p1++;
                    break;
                } else if (ca[ii] < cb[ii]) {
                    break;
                }
            }
        }
    }

    cout << "Broj pobjeda prvog player-a: " << p1 << endl;
}
