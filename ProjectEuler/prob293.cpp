#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23};
set<ll> result;

// ll LIMIT = 9999999;
ll LIMIT = 1e9;

bool check(vector<ll> l) {
    if (l.size() == 0)
        return true;
    set<ll> s(l.begin(), l.end());
    vector<ll> l2(s.begin(), s.end());
    for (int i = 0; i < l2.size(); i++)
        if (i != l2[i])
            return false;
    return true;
}

void solve(ll curr, vector<ll> nums, int rb) {
    if (curr % 2 == 1 && curr != 1) {
        return;
    }

    if (curr >= LIMIT) {
        return;
    }
    if (curr != 1) {
        result.insert(curr);
    }

    for (int i = rb; i < (int)primes.size(); i++) {
        if (nums.size() == 0 && i != 0)
            break;
        else if ((int)nums.size() > 0 && nums.back() != i && nums.back() != i - 1)
            break;
        nums.push_back(i);
        curr *= primes[i];
        if (!check(nums)) {
            curr /= primes[i];
            nums.pop_back();
            continue;
        }
        solve(curr, nums, i);
        curr /= primes[i];
        nums.pop_back();
    }
}

bool isPrime(ll n) {
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (ll i = 3; i <= sqrt(n) + 1; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    solve(1, vector<ll>(), 0);
    vector<ll> arr(result.begin(), result.end());
    cout << "First couple of numbers: ";
    for (int i = 0; i < 12; i++)
        cout << arr[i] << " ";
    cout << endl;

    ll summ = 0;
    set<ll> mSet;
    for (int i = 0; i < (int)arr.size(); i++) {
        ll m = 3;
        while (!isPrime(arr[i] + m)) {
            m += 2;
        };
        mSet.insert(m);
    }

    cout << "Sum: " << accumulate(mSet.begin(), mSet.end(), 0) << endl;

    return 0;
}