#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    
    int summ = 0;
    long long div = 5;
    while (n / div > 0) {
        summ += n / div;
        div *= 5;
    }

    cout << summ << "\n";
    return 0;
}