#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    unsigned long long ul = 9;
    unsigned long long dl = 1;

    unsigned long long cnt = 0;
    unsigned long long len = 1;
    vector<unsigned long long> limits;
    while (cnt < 1e18) {
        cnt += (ul - dl + 1) * len;
        limits.push_back(cnt);
        len ++;
        ul *= 10;
        ul += 9;
        dl *= 10;
    }
    int q;
    cin >> q;
    for (int t = 0; t < q; t ++) {
        unsigned long long n;
        cin >> n;
        int i;
        for (i = 0; i < limits.size(); i ++) {
            if (limits[i] < n) continue;
            else break;
        }
        int numOfDigits = i + 1;
        long long digitInSpecificRange = n - ((i == 0) ? 0 : limits[i - 1]) - 1;
        long long number = pow(10, numOfDigits - 1) + digitInSpecificRange / numOfDigits;
        int ordinal = digitInSpecificRange % numOfDigits;
        string numStr = to_string(number);
        cout << numOfDigits << " " << digitInSpecificRange << " " << number << " " << ordinal << endl;
        cout << numStr[ordinal] << '\n';    
    }

    return 0;
}