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
    cin.tie(NULL)->sync_with_stdio(false);

    int limit = 1000001;
    int* facts = new int[limit];
    facts[0] = 1;
    
    long long modul = 1e9 + 7;

    long long mp = 1;
    for (int i = 1; i <= limit; i ++) {
        mp *= i;
        mp %= modul;
        facts[i] = (int)mp;
    }

    string s;
    cin >> s;
    int hist[26] = {0};
    for (int i = 0; i < s.size(); i ++) {
        hist[s[i] - 'a'] ++;
    }

    long long up = facts[s.size()];
    long long dw = 1;
    for (int i = 0; i < 26; i ++) {
        if (hist[i] > 0) {
            dw *= facts[hist[i]];
            dw %= modul;
        }
    }

    long long mul = pw(dw, modul - 2, modul);
    cout << (mul * up) % modul;

    return 0;
}