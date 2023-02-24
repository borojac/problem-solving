#include <bits/stdc++.h>

using namespace std;

void generate_all(int k, long long* p, int& n, long long& minn, vector<int>& res, long long& uk) {
    if (k == n) {
        long long tmpSumm = 0;
        for (int i = 0; i < (int)res.size(); i ++) {
            tmpSumm += p[res[i]];
        }
        if (minn > abs(tmpSumm - (uk - tmpSumm))) {
            minn = abs(tmpSumm - (uk - tmpSumm));
        }
    } else {
        res.push_back(k);
        generate_all(k + 1, p, n, minn, res, uk);
        res.pop_back();
        generate_all(k + 1, p, n, minn, res, uk);
    }
}

int main() {
    int n;
    cin >> n;
    long long p[n];
    long long summ = 0;
    for (int i = 0; i < n; i ++) {
        cin >> p[i];
        summ += p[i];
    }

    long long minn = summ;
    vector<int> vec;
    generate_all(0, p, n, minn, vec, summ);

    cout << minn;
}
// 1 2 3 4 7