#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> combs;

void combinationUtil(int arr[], int n, int r,
                     int index, int data[], int i)
{
    if (index == r)
    {
        vector<int> tmp;
        for (int j = 0; j < r; j++)
        {
            tmp.push_back(data[j]);
        }

        combs.push_back(tmp);
        return;
    }

    if (i >= n)
        return;

    data[index] = arr[i];
    combinationUtil(arr, n, r, index + 1, data, i + 1);

    combinationUtil(arr, n, r, index, data, i + 1);
}

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n == 3)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}

vector<int> getAnotherThree(vector<int> t)
{
    vector<int> res;
    for (int i = 0; i < 6; i++)
    {
        if (find(t.begin(), t.end(), i) == t.end())
        {
            res.push_back(i);
        }
    }

    return res;
}

void printVec(vector<int> v)
{
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[6] = {0, 1, 2, 3, 4, 5};
    int n = 6;
    int r = 3;
    int data[r];
    combinationUtil(arr, n, r, 0, data, 0);

    for (int i = 0; i < combs.size(); i++)
    {
        int ciff = 0;
        if (combs[i][0] == 0)
            ciff++;

        vector<int> vec1 = combs[i];
        vector<int> vec2 = getAnotherThree(combs[i]);
        for (int num = 0; num <= 999; num++)
        {
            int c1, c2, c3;
            if (vec1[0] != 0 && num < 100)
                continue;
            if (num < 10)
            {
                c1 = 0;
                c2 = 0;
                c3 = num;
            }
            else if (num < 100)
            {
                c1 = 0;
                c2 = num / 10;
                c3 = num % 10;
            }
            else
            {
                c1 = num / 100;
                c2 = (num / 10) % 10;
                c3 = num % 10;
            }
            int cntPrime = 0;

            int minn = 111111110;
            for (int ci = ciff; ci <= 9; ci++)
            {
                int numm = 0;
                numm += pow(10, 5 - vec1[0]) * ci;
                numm += pow(10, 5 - vec1[1]) * ci;
                numm += pow(10, 5 - vec1[2]) * ci;
                numm += pow(10, 5 - vec2[0]) * c1;
                numm += pow(10, 5 - vec2[1]) * c2;
                numm += pow(10, 5 - vec2[2]) * c3;
                if (isPrime(numm))
                    cntPrime++;
                if (numm < minn)
                {
                    minn = numm;
                }
            }
            if (cntPrime >= 8)
            {
                cout << minn << endl;
            }
        }
    }

    return 0;
}