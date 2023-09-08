// B-40min
#include <bits/stdc++.h>
using namespace std;
#define loop           	for (int i = 0; i < n; i++)

void Solve()
{
	int n;cin>>n;
	string sa,sb;
	cin>>sa>>sb;
	int ans = 0;
	loop {
		if(sa[i] == '1'){
			if(i> 0 and sb[i-1] =='1') 
				sb[i-1]='0',ans++;
			else if( i<n-1 and sb[i+1] == '1')
				sb[i+1] ='0',ans++;
		}
		else {
			if(sb[i] == '1') sb[i]='0',ans++;
		}
	}
	cout<<ans<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int Testcase = 1;
	cin>>Testcase;

	while (Testcase--) Solve();
	 return 0;
}