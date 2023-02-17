#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    srand(time(NULL));

    long long win = 0;
    long long limit = 1e10;
    for (long long i = 1; i <= limit; i ++) {
        int a = rand() % 4 + 1;
        int b = rand() % 6 + 1;
        if (a < b) {
            win ++;
        }
    }
    cout << setprecision(12) ;
    cout << (double) win / limit;
    
    return 0;
}