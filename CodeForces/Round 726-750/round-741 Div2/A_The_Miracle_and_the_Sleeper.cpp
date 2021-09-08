#include <bits/stdc++.h>
using namespace std;

#define int long long

void Solve()
{
	int l, r; cin>>l>>r;
	if ( l > r/2) cout<<r%l<<endl;
	else cout<<((r-1) % (r+1)/2) <<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Testcase = 1; cin>>Testcase;
	while (Testcase--) Solve();
}