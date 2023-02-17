#include <bits/stdc++.h>

using namespace std;

int main() {

    int q;
    cin >> q;
    deque<pair<long long, long long>> state;
    for (int i = 0; i < q; i ++) {
        int op;
        cin >> op;
        if (op == 1) {
            int num, c;
            cin >> num >> c;
            state.push_back({c, num});
        } else {
          long long c;
          cin >> c;

        long long summ = 0;
          while(true) {
              if (c == 0) break;
              if (state.front().first <= c) {
                  c -= state.front().first;
                  summ += state.front().first*state.front().second;
                  state.pop_front();
              } else {
                  state[0].first -= c;
                  summ += state.front().second * c;
                  c = 0;
                  break;
              }
          }
          cout << summ << endl;
        }
    }

    return 0;
}