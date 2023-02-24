#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        long long cnt = 0;
        long long n;
        cin >> n;
        set<long long> st;
        for (int i = 1; i * i <= n; i++)
        {
            st.insert(i * i);
        }

        for (int i = 1; i * i * i <= n; i++)
        {
            st.insert(i * i * i);
        }
        cout << st.size() << endl;
    }

    return 0;
}