#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    priority_queue<int, vector<int>, greater<int>> h;

    while (n--) {
        int x;
        cin >> x;

        if (h.size() < k)
            h.push(x);
        else if (x > h.top()) {
            h.pop();
            h.push(x);
        }

        if (h.size() < k)
            cout << -1 << endl;
        else
            cout << h.top() << endl;
    }
    return 0;
}