#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> sf(long long a, long long b) {
    return make_pair(b, 2*b + a);
}

pair<long long, long long> finalSf(long long a, long long b) {
    return make_pair(a + b, b);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0;

    int limit = 100;

    for (int i = 2; i <= limit; i ++) {
        long long sa = 1, sb = 2;
        for (int j = 1; j < i; j ++) {
            pair<long long, long long> res = sf(sa, sb);
            sa = res.first;
            sb = res.second;
        }
        pair<long long, long long> fRes = finalSf(sa, sb);
        cout << fRes.first << " " << fRes.second << "   " << floor(log(fRes.first) / log(10)) << " " << floor(log(fRes.second)/log(10)) << endl;
        if (floor(log(fRes.first)/ log(10)) > floor(log(fRes.second)/ log(10))) {
            cnt ++;
        }
    }
    cout << cnt;
    return 0;
}