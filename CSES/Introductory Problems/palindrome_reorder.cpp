#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    int hist[26] = {0};
    
    int N = str.length();
    for (int i = 0; i < N; i ++) {
        hist[str[i] - 'A'] ++;
    }
    int oddCnt = 0;
    for (int i = 0; i < 26; i ++) {
        if (hist[i] % 2 == 1) {
            oddCnt ++;
        }
    }
    if (oddCnt > 1) {
        cout << "NO SOLUTION" << "\n";
        return 0;
    }

    for (int i = 0; i < 26; i ++) {
        if (hist[i] % 2 == 0) {
            for (int j = 0; j < hist[i] / 2; j ++) {
                cout << (char) (i + 'A');
            }
            if (oddCnt == 0)
                hist[i] /= 2;
        }
    }

    if (oddCnt == 1) {
        for (int i = 0; i < 26; i ++) {
            if (hist[i] % 2 == 1) {
                for (int j = 0; j < hist[i]; j ++)
                    cout << (char) (i + 'A');
                hist[i] = 0;
            }
            if (hist[i] % 2 == 0) hist[i] /= 2;
        }        
    }

    for (int i = 25; i >= 0; i --) {
        for (int j = 0; j < hist[i]; j ++) {
            cout << (char) (i + 'A');
        }
    }

    return 0;
}