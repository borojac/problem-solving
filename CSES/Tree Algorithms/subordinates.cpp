#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> mp;

class TreeNode {
public:
    int val;
    TreeNode(int val){
        this->val = val;
    }
    vector<TreeNode*> childs;

    void fill() {
        for (int i = 0; i < (int)mp[this->val].size(); i ++) {
            childs.push_back(new TreeNode(mp[this->val][i]));
        }
        for (int i = 0; i < (int)childs.size(); i ++) {
            childs[i]->fill();
        }
    }
};

vector<pair<int, int>> res;

int cnt(TreeNode* root) {
    int summ = 0;
    for (int i = 0; i < (int)root->childs.size(); i ++) {
        summ++;
        summ += cnt(root->childs[i]); 
    }
    res.push_back(make_pair(root->val, summ));
    return summ;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {

    int n;
    cin >> n;
    TreeNode* root = new TreeNode(1);
    for (int i = 0; i < n - 1; i ++) {
        int x;
        cin >> x;
        mp[x].push_back(i + 2);
    }
    // for (int i = 0;i <5; i ++) {
    //     cout << i + 1 << " " << mp[i + 1].size();
    //     for (int j = 0; j < mp[i + 1].size(); j ++) {
    //         cout << " " << mp[i + 1][j] ;
    //     }
    //     cout << endl;
    // }

    root->fill();
    cnt(root);
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < (int)res.size(); i ++) {
        cout << res[i].second << " ";
    }



    return 0;
}