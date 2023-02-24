#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> schedule;

void initMat(int** mat, int n){
    mat = new int*[n];
    for (int i = 0; i < n; i ++)
        mat[i] = new int[n];
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            mat[i][j] = 0;
}

int posX, posY;

bool checkMat(int** mat, int n, int row, int col, int val) {
    int rows = 0;
    int cols = 0;
    if (mat[row][row] == val || mat[col][col] == val)
        return false;
    for (int i = 0; i < max(row, col); i ++) {
        if (mat[row][i] == val)
            rows ++;
        if (mat[i][col] == val)
            cols ++;
    }
    if (rows > 0 || cols > 0)
        return false;
    return true;
}

bool solved;

void printMat(int** mat, int n) {
    for (int i = 0; i < n; i ++) {
        cout << endl;
        for (int j = 0; j < n; j ++) {
            cout << mat[i][j];
            if (j != n - 1)
                cout << " ";
        }
    }
}

bool checkComplete(int** mat, int n, int k) {
    int tmpS = 0;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n;j ++)
            if (mat[i][j] == 0)
                return false;
            else if (i == j)
                tmpS += mat[i][j];
    if (k == tmpS)
        return true;
    return false;
}

int getMin(int** mat, int n, int k, int xx) {
    int sum = 0;
    for (int i = 0; i < xx; i ++)
        sum += mat[i][i];
    k = k - sum;

    int tmpArr[n] = {0};
    for (int i = xx; i < n; i ++) {
        tmpArr[i] ++;
        k --;
    }
    int pos = n - 1;
    while (k > 0 && pos >= xx) {
        if (tmpArr[pos] < n){
            tmpArr[pos] ++;
            k --;
        } else {
            pos -= 1;
        }
    }
    if (k > 0) 
        return -1;
    return tmpArr[xx];
}

void solveComplete(int** mat, int n, int num, int k) {
    if (num == schedule.size()) {
        solved = true; 
        return;
    }

    if (num == schedule.size())
        return;

    int x = schedule[num].first;
    int y = schedule[num].second;

    for (int i = 0; i < n; i ++) {
        int val = i + 1;
        // if (x == y) {
        //     int tmpMin = getMin(mat, n, k, x);
        //     if (tmpMin == -1)
        //         return ;
        //     if (val < tmpMin)
        //         continue;
        // } 

        if (checkMat(mat, n, x, y, val)) {
            int tmpS = 0;
            int flag0 = false;
            for (int j = 0; j < n; j ++) {
                tmpS += mat[j][j];
                if (mat[j][j] == 0)
                    flag0 = true;
            }
            if (tmpS > k)
                continue;
            if (tmpS < k && !flag0)
                continue;
            mat[x][y] = val;
            solveComplete(mat, n, num + 1, k);
            if (solved)
                return;
            mat[x][y] = 0;
        }
    }
}

void initSchedule(int n) {
    schedule.clear();
    for (int i = 0; i < n; i ++)
        schedule.push_back({i, i});
    
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++) {
            if (i != j)
                schedule.push_back({i, j});
        }

}

void initSchedule2(int n) {
    schedule.clear();
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++) {
            if (i != j)
                schedule.push_back({i, j});
        }

}
bool initDiag(int* diag, int n, int k) {

    for (int i = 0; i < n; i ++){
        diag[i] ++;
        k --;
    }

    for (int i = n - 1; i >= 0 && k > 0; i --) {
        while (diag[i] < n && k > 0){
            diag[i] ++;
            k --;
        }
    }


    bool same = true;
    int tmpVal = diag[0];
    for (int i = 1; i < n - 1; i ++)
        if (tmpVal != diag[i]) {
            same = false;
            break;
        }
    if (same && diag[n-1] != tmpVal) {
        diag[n - 2] ++;
        diag[n - 1] --;
    }
    same = true;
    tmpVal = diag[1];
    for (int i = 1; i < n; i ++){
        if (tmpVal != diag[i]){
            same = false;
            break;
        }
    }
    if (same && diag[0] != tmpVal) {
        diag[0] ++;
        diag[1] --;
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; 
    cin >> t;

    for (int i = 0; i < t; i ++) {
        int n, k;
        cin >> n >> k;
        if (k < n || k > n*n || k == n + 1 || k == n * n - 1){
            cout << "Case #" << i + 1 << ": IMPOSSIBLE";
            if (i != t - 1)
                cout << endl;
            continue;
        }
        int** mat;
        posX = posY = 0;
        mat = new int*[n];
        for (int i = 0; i < n; i ++)
            mat[i] = new int[n];
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                mat[i][j] = 0;

        solved = false;
        int diag[n] = {0};
        initDiag(diag, n, k);
        initSchedule2(n);
        for (int i = 0; i < n; i ++)
            mat[i][i] = diag[i];
        solveComplete(mat, n, 0, k);
        if (!solved){
                cout << "Case #" << i + 1 << ": IMPOSSIBLE";
                if (i != t - 1)
                    cout << endl;
                continue;
            }

        cout << "Case #" << i + 1 << ": POSSIBLE";
        printMat(mat, n);
        if (i != t - 1)
            cout << endl;

    }
}