#include <bits/stdc++.h>
using namespace std;

long long countOps = 0;
int maxLvl = 0;
int lvl = 0;

void solve(int x) {
    lvl++;
    if (lvl > maxLvl) maxLvl = lvl;

    if (x <= 2) {
        countOps++;
        lvl--;
        return;
    }

    int t = x;
    while (t > 0) {
        vector<int> arr(x);
        for (int j = 0; j < x; j++) {
            arr[j] = j + (t & 1);
            countOps++;
        }
        t >>= 1;
    }

    vector<int> v(x);
    for (int i = 0; i < x; i++) {
        v[i] = i * i + 1;
        countOps++;
    }

    reverse(v.begin(), v.end());
    countOps += x;

    solve(x / 2);
    solve(x / 2);
    solve(x / 2);

    lvl--;
}

int main() {
    int n;
    cin >> n;

    solve(n);

    cout << "Operations = " << countOps << endl;
    cout << "Max depth = " << maxLvl << endl;
}

/* Recurrence Relation --->     T(n) = 3T(n/2) + n log n
Time Complexity --->    T(n) = Θ(n^(log2 3))
Recursion Depth --->    Θ(log n)
*/