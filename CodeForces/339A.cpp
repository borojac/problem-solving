#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    string str = "";
    getline(cin, line);
    
    for (char s : line){
        if (s != '+'){
            str += s;
        }
    }

    sort(str.begin(), str.end());

    for (int i = 0; i < str.size(); i ++){
        std::cout << str[i];

        if (i != str.size() - 1)
            std::cout << "+";
    }
}