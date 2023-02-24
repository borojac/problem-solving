#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n];
    long long summ = 0;
    for (int i = 0; i <  n; i ++) {
        cin >> p[i];
        summ += p[i];
    }

    sort(p, p + n);

    int t1 =  p[n / 2];
    int t2 = p[n / 2 + 1];
    int t3 = p[n/2 - 1];

    long long s1= 0, s2 = 0, s3 = 0;
    for (int i = 0; i < n; i ++) {
        s1 += abs(p[i] - t1);
        s2 += abs(p[i] - t2);
        s3 += abs(p[i] - t3);
    }

    cout << min (s1, min (s2, s3));

    return 0;
}