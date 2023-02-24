#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    char hist[26] = {0};
    int N = str.length();
    for (int i = 0; i < N; i ++) {
        hist[str[i] - 'a'] ++;
    }

    long long num = 1;
    for (int i = 1; i <= N; i ++)
        num *= i;
    
    for (int i = 0; i < 26; i ++) {
        if (hist[i] > 1) {
            long long tmp = 1;
            for (int j = 1; j <= hist[i]; j ++)
                tmp *= j;
            num /= tmp;
        }
    }

    cout << num << "\n";

    sort(str.begin(), str.end());
    set<string> outputs;
    do {
        outputs.insert(str);
    }while(next_permutation(str.begin(), str.end())); 
    
    for (auto s : outputs) {
        cout << s << "\n";
    }
    return 0;
}