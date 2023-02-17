#include <bits/stdc++.h>

using namespace std;

string fn(long long num) {
    int hist[10] = {0};
    while (num) {
        int digit = num % 10;
        hist[digit] ++;
        num /= 10;
    }
    string res = "";
    for (int i = 0; i < 10; i ++) {
        res += to_string(hist[i]) + "#" + to_string(i) + "#";
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    map<string, pair<int, int>> mp;

    for (long long i = 1; ; i ++) {
        long long num = i * i * i;
        string key = fn(num);
        if (mp[key].first == 0) {
            mp[key].first ++;
            mp[key].second = i;
        } else {
            mp[key].first ++;
            if (mp[key].first == 5) {
                cout << mp[key].second;
                break;
            }
        }
    }

    return 0;
}