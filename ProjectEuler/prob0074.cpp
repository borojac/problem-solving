#include <bits/stdc++.h>

using namespace std;

long long fact(long long x) {
    long long p = 1;
    for (int i = 2; i <= x; i++)
        p *= i;
    return p;
}

long long f(long long x) {
    long long s = 0;
    while (x > 0) {
        int d = x % 10;
        s += fact(d);
        x /= 10;
    }

    return s;
}

int main() {
    int LIMIT = 1000000;
    set<long long> x;
    int cnt = 0;
    for (long long i = 1; i < LIMIT; i++) {
        long long num = i;
        x.insert(num);
        long long t = 1;
        while ((int)x.size() == t) {
            t++;
            num = f(num);
            x.insert(num);
        }
        if (x.size() == 60)
            cnt++;
        x.clear();
    }

    cout << cnt << endl;
    return 0;
}