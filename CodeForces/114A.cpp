#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    long long n, poww;
    cin >> n >> poww;
    long long result = 1;
    while(result < poww){
        result *= n;
    }
    cout << ((result == poww) ? "YES" : "NO") << endl << pow - 1;
    return 0;
}