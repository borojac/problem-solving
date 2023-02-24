#include <bits/stdc++.h>

using namespace std;

void initMat(int** mat, int n) {
    int beg = 0;
    for (int i = 0; i < n;i ++)
        mat[i][i] = 1;
    for (int i = 0; i < n; i ++) {
        int cnt = 1;
        int val = 2;
        while (cnt <= n - 1){
            mat[i][(i + cnt) % n] = val ++;
            cnt ++;
        }
    }

}

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

bool checkDiag(int** mat, int n, int* diag) {
    for (int i = 0; i < n; i ++)
        if (mat[i][i] != diag[i])
            return false;
    return true;
}

bool checkDiag2(int** mat, int n, int*diag){
    for (int i = 0; i < n - 2; i ++)
        if (mat[i][i] != diag[i])
            return false;
    return true;
}

void swapRows(int** mat, int n, int r1, int r2) {
    for (int i = 0; i < n; i ++){
        int temp = mat[r1][i];
        mat[r1][i] = mat[r2][i];
        mat[r2][i] = temp;
    }
}

void swapCols(int** mat, int n, int c1, int c2) {
    for (int i = 0; i < n; i ++){
        int temp = mat[i][c1];
        mat[i][c1] = mat[i][c2];
        mat[i][c2] = temp;
    }
}
bool solved = false;
void solve(int** mat, int* diag, int n, int* rows, int* cols, int ii) {
    if (checkDiag(mat, n, diag)) {
        solved = true;
        return;
    }
    int i = ii % n;
    int target = diag[i];
    int targetRow = 0;
    int targetCol = 0;
    for (int j = 0; j < n; j ++) {
        if (mat[j][i] == target){
            targetRow = j;
            break;
        }
    }
    for (int j = 0; j < n; j ++) {
        if (mat[i][j] == target){
            targetCol = j;
            break;
        }
    }

    if (rows[targetRow] == 0){
        rows[i] = 1;
        cols[i] = 1;
        swapRows(mat, n, i, targetRow);
        solve(mat, diag, n, rows, cols, i + 1);
        if (solved)
            return;
        swapRows(mat, n, i, targetRow);
        rows[i] = 0;
        cols[i] = 0;
    } 
    if (cols[targetCol] == 0){
        rows[i] = 1;
        cols[i] = 1;
        swapCols(mat, n, i, targetCol);
        solve(mat, diag, n, rows, cols, i + 1);
        if (solved)
            return;
        rows[i] = 0;
        cols[i] = 0;
        swapCols(mat, n, i, targetCol);
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
            std::cout << "Case #" << i + 1 << ": IMPOSSIBLE";
            if (i != t - 1)
                std::cout << endl;
            continue;
        }
        int** mat;
        mat = new int*[n];
        for (int i = 0; i < n; i ++)
            mat[i] = new int[n];
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                mat[i][j] = 0;
        int diag[n] = {0};
        initMat(mat, n);
        initDiag(diag, n, k);
        
        printMat(mat, n);
        cout << endl;

        for (int i = 0; i < n; i ++)
            cout << diag[i]  << " " ;

        int rows[n] = {0};
        int cols[n] = {0};

        solve(mat, diag, n, rows, cols, 0);
        solved = false;
        for (int i = 0; i < n; i ++){
            rows[i] = 0;
            cols[i] = 0;
        }
        if (solved){
            std::cout << "Case #" << i + 1 << ": POSSIBLE";
            printMat(mat, n);
            if (i != t - 1)
                std::cout << endl;
        } else {
            std::cout << "Case #" << i + 1 << ": IMPOSSIBLE";
        }
    }
}
