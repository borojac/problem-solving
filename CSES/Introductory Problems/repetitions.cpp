#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string dna;
    cin >> dna;
    int maxx = 1;
    char curr = dna[0];
    int currCnt = 1;
    int N = dna.length();
    for (int i = 1; i < N; i ++) {
        if (curr == dna[i]) {
            currCnt++;
        } else {
            curr = dna[i];
            if (currCnt > maxx)
                maxx = currCnt;
            currCnt = 1;
        }
    }
    if (currCnt > maxx)
        maxx = currCnt;
    
    cout << maxx << "\n";

    return 0;
}