#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) {
    if (x == 2)
        return true;
    for (int i = 2; i <= sqrt(x); i ++)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> primes;
    for (int i = 2; i <= 1e6; i ++) 
        if (isPrime(i))
            primes.push_back(i);

    cout << primes.size();
    return 0;
}