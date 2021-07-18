#include <bits/stdc++.h>
using namespace std;

void calc(int l, int r, int k) {
    if (l == r) {
        cout << "! " << l << endl;
        return;
    }
    int m = (l + r) / 2;
    cout << "? " << l << " " << m << endl;
    int sum;
    cin >> sum;
    if ((m - l + 1) - sum >= k) {
        calc(l, m, k);
    } else {
        calc(m + 1, r, k - (m - l + 1) + sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t, k;
    cin >> n >> t >> k;
    calc(1, n, k);
}