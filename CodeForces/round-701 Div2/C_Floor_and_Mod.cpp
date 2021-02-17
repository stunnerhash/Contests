#include <bits/stdc++.h>
using namespace std;

#define  endl "\n"
#define ll long long
void Solve()
{
    ll ans=0, x, y;
	cin >> x >> y;
    for (int i = 1; i * i < x; i++)
    {
        ll tmp = min(y, (x / i) - 1);
        ans += max(tmp - i, 0LL);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int T= 1;
    cin >> T;
    while (T--)Solve();
    return 0;
}