#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    long long tickets[n], prices[m];
    for (int i = 0; i < n; i ++) {
        cin >> tickets[i];
    }
    for (int i = 0; i < m; i ++) {
        cin >> prices[i];
    }

    sort(tickets, tickets + n);
    sort(prices, prices + m);
    reverse(tickets, tickets + n);
    reverse(prices, prices + m);

    return 0;
}