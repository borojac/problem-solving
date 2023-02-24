#include <bits/stdc++.h>

using namespace std;

vector<vector<double>> NUMS;

void combinationUtil(int arr[], int data[],
                     int start, int end,
                     int index, int r);

void printCombination(int arr[], int n, int r)
{
    int data[r];

    combinationUtil(arr, data, 0, n - 1, 0, r);
}

void combinationUtil(int arr[], int data[],
                     int start, int end,
                     int index, int r)
{
    if (index == r)
    {
        vector<double> tmp;
        for (int j = 0; j < r; j++)
            tmp.push_back(data[j]);
        NUMS.push_back(tmp);
        return;
    }

    for (int i = start; i <= end &&
                        end - i + 1 >= r - index;
         i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i + 1,
                        end, index + 1, r);
    }
}

char getOp(int x)
{
    if (x == 0)
        return '+';
    if (x == 1)
        return '-';
    if (x == 2)
        return '*';
    return '/';
}

double calc(char op, double a, double b)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    return a / b;
}

bool check(double x)
{
    double intpart;
    return x == trunc(x);
    // return modf(x, &intpart) == 0.0;
}

int main()
{
    // 1-9 => 9 nad 4
    NUMS = vector<vector<double>>();
    vector<vector<char>> OPS;
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int r = 4;
    int n = 9;
    printCombination(nums, n, r);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                vector<char> tmp;
                tmp.push_back(getOp(i));
                tmp.push_back(getOp(j));
                tmp.push_back(getOp(k));

                OPS.push_back(tmp);
            }
        }
    }
    int maxx = -1;
    vector<double> res;
    for (auto xx : NUMS)
    {
        vector<vector<double>> NUMSS;
        sort(xx.begin(), xx.end());
        do
        {
            vector<double> tmp(xx);
            NUMSS.push_back(tmp);
        } while (next_permutation(xx.begin(), xx.end()));

        int maxCon = 0;
        set<int> s;
        for (auto num : NUMSS)
        {
            for (auto op : OPS)
            {
                // if (num[0] == 3 && num[1] == 4 && num[2] == 2 && num[3] == 1)
                // {
                //     cout << op[0] << " " << op[1] << " " << op[2] << endl;
                // }

                double x = calc(op[0], num[0], num[1]);
                x = calc(op[1], x, num[2]);
                x = calc(op[2], x, num[3]);
                if (check(x))
                    s.insert(x);
                x = calc(op[1], calc(op[0], num[0], num[1]), calc(op[2], num[2], num[3])); // (1 1) (1 1)
                if (check(x))
                    s.insert(x);
                x = calc(op[1], num[1], num[2]);
                x = calc(op[0], num[0], x);
                x = calc(op[2], x, num[3]);
                if (check(x))
                    s.insert(x);
                x = calc(op[1], num[1], num[2]);
                x = calc(op[2], x, num[3]);
                x = calc(op[0], num[0], x);
                if (check(x))
                    s.insert(x);
                x = calc(op[0], num[0], num[1]);
                x = calc(op[1], x, num[2]);
                x = calc(x, op[2], num[3]);
                if (check(x))
                    s.insert(x);
                x = calc(op[0], num[0], calc(op[1], num[1], calc(op[2], num[2], num[3])));

                if (check(x))
                    s.insert(x);
                x = calc(op[2], calc(op[0], num[0], calc(op[1], num[1], num[2])), num[3]); // 1 (1 1) 1
                if (check(x))
                    s.insert(x);
                x = calc(op[2], calc(op[1], calc(op[0], num[0], num[1]), num[2]), num[3]); // (1 1) 1 1
                if (check(x))
                    s.insert(x);
                x = calc(op[0], num[0], calc(op[1], num[1], calc(op[2], num[2], num[3]))); // 1 1 (1 1)
                // if (num[0] == 3 && num[1] == 4 && num[2] == 2 && num[3] == 1 && op[0] == '+' && op[1] == '*' && op[2] == '-')
                // {
                //     cout << x << endl;
                //     cout << check(x) << endl;
                // }
                if (check(x))
                    s.insert(x);
                x = calc(op[2], calc(op[1], calc(op[0], num[0], num[1]), num[2]), num[3]); // (1 1 1) 1
                if (check(x))
                    s.insert(x);
                x = calc(op[2], calc(op[0], num[0], calc(op[1], num[1], num[2])), num[3]); // (1 1 1) 1
                if (check(x))
                    s.insert(x);
                x = calc(op[0], num[0], calc(op[2], calc(op[1], num[1], num[2]), num[3])); // 1 (1 1 1)
                if (check(x))
                    s.insert(x);
                x = calc(op[0], num[0], calc(op[1], num[1], calc(op[2], num[2], num[3]))); // 1 (1 1 1)
                if (check(x))
                    s.insert(x);
            }
        }
        vector<int> t;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            if (*it > 0)
                t.push_back(*it);
        }
        // cout << num[0] << " " << num[1] << " " << num[2] << " " << num[3];
        // cout << endl;
        sort(t.begin(), t.end());
        while ((int)t[maxCon] == maxCon + 1)
            maxCon++;
        if (maxCon > maxx)
        {
            maxx = maxCon;
            res = vector<double>(xx);
        }
    }

    cout << maxx << endl;
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}