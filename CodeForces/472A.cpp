#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) {
    if (x == 2)
        return true;
    for (int i = 2; i <= x / 2; i ++){
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 3; i <= n / 2 ; i ++){
        if (!isPrime(i) && !isPrime(n - i)){
            cout << i << " " << n - i;
            break;
        }
    }
}