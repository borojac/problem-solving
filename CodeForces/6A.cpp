#include <bits/stdc++.h>

using namespace std;

double p(double a, double b, double c) {
    double s = (a + b+ c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    double s1 = p(a, b, c);
    double s2 = p(a, b, d);
    double s3 = p(a, c, d);
    double s4 = p(b, c, d);
    
    if (s1 > 0 || s2 > 0 || s3 > 0 || s4 > 0) {
        cout << "TRIANGLE";
    } else if (s1 == 0 || s2 == 0 || s3 == 0 || s4 == 0) {
        cout << "SEGMENT";
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}