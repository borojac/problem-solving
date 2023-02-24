#include <bits/stdc++.h>

using namespace std;

class Edge {
public:
    int x, y;
    Edge() {
        this->x = 0;
        this->y = 0;
    }
    Edge(int x, int y) {
        this->x = x;
        this->y = y;
    }

    bool operator<(const Edge& e) {
        return x < e.x || (x == e.x && y < e.y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> lab;
    map<Edge, vector<Edge>> mp;
    Edge startingEdge;
    Edge endingEdge;
    for (int i = 0; i < n; i ++) {
        string line;
        cin >> line;
        for (int j = 0; j < line.size(); j ++) {
            if (line[j] == '.') {
                vector<Edge> tmp;
                Edge tmpEdge(i, j);
                mp.insert({tmpEdge, tmp});
            } else if 
        }
    }

    return 0;
}