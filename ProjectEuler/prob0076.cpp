#include <bits/stdc++.h>

using namespace std;

long long cnt = 0;
int limit = 100;

void solve(int& sum, vector<long long> s, int index) {
    if (sum == limit) {
        cnt += 1;
        return ;
    }

    for (int i = index; i < (int) s.size(); i ++) {
        if (sum + s[i] > limit) {
            break;
        }
        sum += s[i];
        solve(sum, s, i);
        sum -= s[i];
    }

    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<long long> vec;
    for (int i = 1; i < limit; i ++) {
        vec.push_back(i);
    }
    int sum = 0;
    solve(sum, vec, 0);
    cout << cnt;

    return 0;
}