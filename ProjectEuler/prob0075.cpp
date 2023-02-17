#include <bits/stdc++.h>

using namespace std;

int getNumOfTriangles(long long L) {
    int cnt = 0;
    for (int i = 1; i < L; i ++) {
        for (int j = i; j < L - i; j ++) {
            
            if (L - i - j > j) {
                long long a = i;
                long long b = j;
                long long c = L - i - j;
                if (a * a + b * b == c * c) {
                    cnt ++;
                }

            } else {
                break;
            }

        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int limit = 1500000;
    int cnt = 0;
    for (int i = 12; i <= limit; i ++) {
        int L = i;
        if (getNumOfTriangles(L) == 1) {
            cnt ++;
        }
    }

    cout << cnt;
    return 0;
}