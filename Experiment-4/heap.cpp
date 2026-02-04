#include <bits/stdc++.h>
using namespace std;

int h[100], n = 0;

void fixUp(int i) {
    while (i && h[(i-1)/2] > h[i]) {
        swap(h[i], h[(i-1)/2]);
        i = (i-1)/2;
    }
}

void fixDown(int i) {
    while (true) {
        int l = 2*i+1, r = 2*i+2, s = i;
        if (l < n && h[l] < h[s]) s = l;
        if (r < n && h[r] < h[s]) s = r;
        if (s == i) break;
        swap(h[i], h[s]);
        i = s;
    }
}

int main() {
    while (true) {
        int ch, x, pos = -1;
        cout << "\n1 Insert\n2 Search\n3 Delete Root\n4 Delete Element\n5 Display\n6 Exit\n";
        cin >> ch;

        if (ch == 1) {
            cin >> x;
            h[n] = x;
            fixUp(n++);
        }

        else if (ch == 2) {
            cin >> x;
            for (int i = 0; i < n; i++)
                if (h[i] == x) { cout << "Found at " << i << endl; pos = i; break; }
            if (pos == -1) cout << "Not found\n";
        }

        else if (ch == 3) {
            if (!n) cout << "Empty\n";
            else {
                cout << "Removed: " << h[0] << endl;
                h[0] = h[--n];
                fixDown(0);
            }
        }

        else if (ch == 4) {
            cin >> x;
            for (int i = 0; i < n; i++)
                if (h[i] == x) { pos = i; break; }

            if (pos == -1) cout << "Not found\n";
            else {
                h[pos] = h[--n];
                fixUp(pos);
                fixDown(pos);
            }
        }

        else if (ch == 5) {
            if (!n) cout << "Empty\n";
            else for (int i = 0; i < n; i++) cout << h[i] << " ";
            cout << endl;
        }

        else if (ch == 6) break;
        else cout << "Invalid\n";
    }
    return 0;
}