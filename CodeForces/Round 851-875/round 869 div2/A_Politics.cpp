#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; 
	cin>>t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int ans = 0;
		string first; cin>>first;
		for (int i = 1; i < n; i++){
			string s; cin>>s;
			if(s == first) ans ++;
		}
		cout<<ans+1<<endl;
	}
	return 0;
}