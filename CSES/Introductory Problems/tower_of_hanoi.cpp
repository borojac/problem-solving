#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, int a, int c, int b) {
    if (n == 1) {
        cout << a << " " << c << '\n';
        return ;
    }
    hanoi(n - 1, a, b, c);
    cout << a << " " << c << '\n';
    hanoi(n - 1, b, c, a);
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << '\n';
    hanoi(n, 1, 3, 2);

}