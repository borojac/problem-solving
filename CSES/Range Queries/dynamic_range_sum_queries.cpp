#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("test_input (1).txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    // Start counting
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    int n, q;
    cin >> n >> q;

    long long arr[n];
    long long summ[n];
    long long tSumm = 0;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        tSumm += arr[i];
        summ[i] = tSumm;
    }

    for (int i = 0; i <q ;i ++) {
        int a, b, o;
        cin >> o >> a >> b;
        if (o == 2) {
            cout << summ[b-1] - summ[a-1] + arr[a-1] << "\n";
        } else {
            int diff = b - arr[a - 1]; // arr[a - 1] + (b - arr[a-1])
            arr[a - 1] = b;
            for (int j = a - 1; j < n; j ++) {
                summ[j] += diff;
            }
        }
    }


    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
}