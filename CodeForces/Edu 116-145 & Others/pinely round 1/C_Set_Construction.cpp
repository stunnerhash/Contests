#include <bits/stdc++.h>
using namespace std;

#define loop           	for (int i = 0; i < n; i++)
#define lop(i, n)      	for (int i = 0; i < n; i++)

#define int long long

void solve()
{
	int n; cin>>n;
	vector<string> s(n);
	loop cin>>s[i];
	vector<int> ans[n];
	loop ans[i].push_back(i+1);
	loop{
		lop(k,n){
			if(s[i][k] == '1') ans[k].push_back(i+1);
		}
	}
	loop{
		cout<<ans[i].size()<<' ';
		sort(ans[i].begin(),ans[i].end());
		for(auto it:ans[i]) cout<<it<<' ';
		cout<<endl;
	}
}

signed main()
{
	int tc = 1;
	cin>>tc;

	while (tc--) solve();
	return 0;
}
