#include <bits/stdc++.h>

using namespace std;

int ff(unsigned long long x) {
    unsigned long long s = 0;
    for (char c : to_string(x)) s += c;

    return s - to_string(x).size() * '0';
}

// Logic is good, but unsigned long long is not enough

int main() {
    unsigned long long num1 = 1, num2 = 2;
    long long f = 1;
    for (int i = 2; i <= 100; i++) {
        unsigned long long tmp = num1;
        num1 = num2;
        if (i % 3 == 0)
            f = 2 * (i / 3);
        else
            f = 1;
        num2 = f * num1 + tmp;
        cout << num2 << " ";
        cout << i << "= " << ff(num2) << endl;
    }
}