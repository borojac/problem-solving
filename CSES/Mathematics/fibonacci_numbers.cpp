#include <bits/stdc++.h>

using namespace std;

class Mat {
public:
    long long m[2][2];
    Mat(long long a, long long b, long long c, long long d) {
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
    }
    Mat() {
        m[0][0] = 0;
        m[0][1] = 1;
        m[1][0] = 1;
        m[1][1] = 1;
    }
    Mat operator*(Mat x) {
        Mat t(this->m[0][0] * x.m[0][0] + m[0][1]*x.m[1][0], m[0][0]*x.m[0][1] + m[0][1] * x.m[1][1], m[1][0]*x.m[0][0] + m[1][1] * x.m[1][0], m[1][0] * x.m[0][1] + m[1][1] * x.m[1][1]);
        for (int i = 0; i < 2; i ++)
            for (int j = 0; j < 2; j ++)
                t.m[i][j] %= (long long)(1e9+7);
        return t;
    }


};

Mat custom_exp(Mat a, long long b) {
    if (b == 0)
        return Mat(1, 0, 0, 1);
    if (b == 1)
        return a;
    if (b % 2 == 0) {
        return custom_exp((a*a), b / 2);
    }
    
    return a * custom_exp(a, b - 1);
}

int main() {
    long long n;
    cin >> n;
    Mat a = custom_exp(Mat(), n);
    cout << (a.m[0][0] * 0 + a.m[0][1] * 1);

    return 0;
}