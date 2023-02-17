#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool isPalindrome(long long m) {
    long long mm = m;
    long long nn = 0;
    while (m) {
        int digit = m % 10;
        nn += digit;
        nn*=10;
        m /= 10;
    }
    nn /= 10;

    return mm == nn;
}

long long sqs(long long num) {
    return (num * (num + 1) * (2 * num + 1)) / 6;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long limit = 1e8;
    long long cnt = 0;
    long long summ = 0;

    auto start = high_resolution_clock::now();

    for (long long i = 1; i <= limit; i ++) {
        if (isPalindrome(i)) {
            for (int j = 2; j <= sqrt(i); j ++) {
                bool naso = false;
                long long fr = sqs(j);
                for (int k = 0; k < j - 1; k ++){
                    long long sc = sqs(k);
                    if (fr - sc == i) {
                        cnt ++;
                        summ += i;
                        naso = true;
                        break;
                    }
                }
                if (naso) {
                    break;
                }
            }
        }
        if (i % 10000000 == 0) {
            cout << i << endl;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "Elapsed time: " << duration.count() << " seconds" << endl;
    cout << cnt << endl << summ << endl;

    return 0;
}