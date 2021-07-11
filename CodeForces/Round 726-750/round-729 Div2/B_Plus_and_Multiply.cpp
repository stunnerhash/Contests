#include <bits/stdc++.h>
using namespace std;

#define int long long
void Solve()
{
	int n,a,b;
	cin>>n>>a>>b;
	bool ok = 0;
	int cnt  = 0;
	int t=1;
	if (a == 1){
    	if ((n-1)%b==0) cout<<"Yes"<<endl;
    	else cout<<"No"<<endl;
		return;
	}
	while(t<=n){
		if(t%b == n%b ){
			ok= true;
			break;
		}
		t=t*a;
	}
	cout<<(ok?"Yes":"No")<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int Testcase = 1;
	cin>>Testcase;

	while (Testcase--) Solve();
	 return 0;
}