#include <bits/stdc++.h>
using namespace std;

#define loop           	for (int i = 0; i < n; i++)
#define all(x)         	x.begin(), x.end()
#define sortall(x)    	sort(all(x))
#define endl           	"\n"
typedef vector<int>    	vi;

#define int long long
void solve()
{
	int n; cin>>n;
	vi a(n); loop cin>>a[i];
	sortall(a);
	cout<<a[n-2]+a[n-1]-a[0]-a[1]<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int tc = 1; cin>>tc;

	while (tc--) solve();
	return 0;
}
