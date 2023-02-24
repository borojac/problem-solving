#include <bits/stdc++.h>

using namespace std;

long long ex(long long base, long long pow) {
	long long ans = 1;
	while (pow) {
		if (pow & 1) ans = ans * base % (1e9+7);
		base = base * base % (1e9+7);
		pow >>= 1;
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long long, long long>> primes;

    long long modul = 1e9 + 7;
    long long tau = 1;
    long long sigma = 1;
    long long pr = 1;

    for (int i = 0; i < n; i ++) {
        long long a, b;
        cin >> a >> b;
        // primes.push_back({a, b});
        tau *= (b + 1);
        tau %= modul;
        
        sigma = sigma * (ex(a, b + 1) - 1) % modul * ex(a - 1, modul - 2) % modul;
        div_prod = expo(div_prod, k[i] + 1) * expo(expo(p[i], (k[i] * (k[i] + 1) / 2)), div_cnt2) % MOD;
    }
    

    
    cout << tau << " " << sigma << " " << "??";
    return 0;
}