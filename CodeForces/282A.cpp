#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    string line;
    getline(cin, line);
    int value = 0;
    for (int i = 0; i < t; i ++){
        getline(cin, line);

        for (char s : line){
            if (s == '+'){
                value ++;
                break;
            } else if (s == '-'){
                value --;
                break;
            }
        }
    }

    cout << value;

}