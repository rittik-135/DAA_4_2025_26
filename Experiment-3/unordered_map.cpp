#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> mp;

    int prefixSum = 0;
    int answer = 0;
    mp[0] = -1;
    for (int i = 0; i < n; i++) {
        char status;
        cin >> status;

        if (status == 'P') {
            prefixSum = prefixSum + 1;
        } else {
            prefixSum = prefixSum - 1;
        }

        if (mp.count(prefixSum) == 1) {
            int length = i - mp[prefixSum];
            if (length > answer) {
                answer = length;
            }
        } else {
            mp[prefixSum] = i;
        }
    }
    cout << answer;
    return 0;
}

// Time Complexity is O(n).