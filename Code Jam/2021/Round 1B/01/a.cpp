#include <bits/stdc++.h>

using namespace std;

bool check(long double h, long double m, long double s) {
    if (abs(fmodl(h, 30) / 30 - m / 360) < 1e-8 && abs(fmodl(m, 6) / 6 - s / 360) < 1e-8)  return true;
    return false;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i ++) {
        long double a, b, c;
        cin >> a >> b >> c;
        long double da = a;
        long double db = b;
        long double dc = c;

        long double h, m, s;
        // long limit = 12;
        for (long double d = 0; ; d += 720) {
            long double oldDa = da;
            long double oldDb = db;
            long double oldDc = dc;
            da -= d ;
            db -= d;
            dc -= d;
        da *= ((1e-10) / 12);
        db *= ((1e-10) / 12);
        dc *= ((1e-10) / 12);
        da = fmodl(da, 360);
        db = fmodl(db, 360);
        dc = fmodl(dc, 360);
        

        // each hour is 360 / 12 deg, 30 deg

            

            if (da < 0)
                da = 360 + da;
            if (db < 0)
                db = 360 + db;
            if (dc < 0)
                dc = 360 + dc;
            
            if (check(da, db, dc)) {
                h = da;
                m = db;
                s = dc;
                break;
            } else if (check(da, dc, db)) {
                h = da;
                m = dc;
                s = db;
                break;
            } else if (check(db, dc, da)) {
                h = db;
                m = dc;
                s = da;
                break;
            } else if (check(db, da, dc)) {
                h = db;
                m = da;
                s = dc;
                break;
            } else if (check(dc, da, db)) {
                h = dc;
                m = da;
                s = db;
                break;
            } else if (check(dc, db, da)) {
                h = dc;
                m = db;
                s = da;
                break;
            }
            da = oldDa;
            db = oldDb;
            dc = oldDc;
        }
        long double summ = (fmodl(s, 6) / ((long double) 1e-10 / 12)) * 720;
        summ += fmodl(h, 30) / ((long double) 1e-10) / 12));
        summ += fmodl(m, 6) / ((long double) 1e-10) / 12))  * 12;
        cout << "Case #" << i + 1 << ": ";
        cout << (long long)(h / 30) << " ";
        cout << (long long)(m / 6) << " ";
        cout << (long long)(s / 6) << " ";
        // cout << 0;
        cout << (long long)((summ) / 720);
        cout << "\n";
    }

    return 0;
}