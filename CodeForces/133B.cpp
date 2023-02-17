#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;
    map<char, string> mp;
    mp['>'] = "1000";
    mp['<'] = "1001";
    mp['+'] = "1010";
    mp['-'] = "1011";
    mp['.'] = "1100";
    mp[','] = "1101";
    mp['['] = "1110";
    mp[']'] = "1111";

    string res = "";
    for  (int i = 0; i < s.size(); i ++) {
        res += mp[s[i]];
    }

    long long summ = 0;
    long long p = 1;
    for (int i = res.size() - 1; i >= 0; i --) {
        if (res[i] == '1') {
            summ += p;
            summ %= 1000003;
        }
        p *= 2;
        p %= 1000003;
    }

    cout << summ;   

    return 0;
}