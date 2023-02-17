#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);

    int tc, n; 
    cin >> tc >> n;

    vector<long long> vec;
    vector<tuple<long long, long long>> res;
    for(int i = 1; i <= n; i++){
        vec.push_back(i);
    }
    while(vec.size() > 1){
        if(vec[vec.size()-1] == vec[vec.size()-2]){
            res.push_back(make_tuple(vec[vec.size()-1], vec[vec.size()-1]));
            vec.pop_back();
        }else{
            int first = vec.size() > 2 ? 3 : 2;
            long long f, s;
            f = vec[vec.size()-first];
            s = vec[vec.size()-1];
            res.push_back(make_tuple(f, s));
            vec.pop_back();
            if(vec[vec.size()-1]==f){
                vec.pop_back();
            }else{
                long long tmp1 = vec.back();
                vec.pop_back();
                vec.pop_back();
                vec.push_back(tmp1);
            }

            vec.push_back(ceil((f+s)/2));

        }
    }
    cout << vec[0] << endl;
    for(int i = 0; i < res.size(); i++){
        cout << get<0>(res[i]) << ' ' << get<1>(res[i]) << endl;
    }
    return 0;
}