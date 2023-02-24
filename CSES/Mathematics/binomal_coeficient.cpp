#include <bits/stdc++.h>

using namespace std;

long long pw(long long a, long long b, long long modul) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 0) {
        return pw((a * a) % modul, b / 2, modul);
    } 
    return (a * pw(a, b - 1, modul)) % modul;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int limit = 1000001;
    int* facts = new int[limit];
    facts[0] = 1;
    int n;
    cin >> n;
    
    long long modul = 1e9 + 7;

    long long mp = 1;
    for (int i = 1; i <= limit; i ++) {
        mp *= i;
        mp %= modul;
        facts[i] = (int)mp;
    }

    for (int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        
        long long dividend = ((long long)facts[b] * facts[a - b]) % modul;
        long long mul = pw(dividend, modul - 2, modul);
        long long res = (mul * facts[a]) % modul;
        cout << res << "\n";
    }




    return 0;
}