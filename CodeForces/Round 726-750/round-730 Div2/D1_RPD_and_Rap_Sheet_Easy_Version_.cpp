#include <bits/stdc++.h>
using namespace std;
#define loop for(int i =0;i<n;i++)
int main()
{
	int t = 1;
	cin>>t;
	while (t--){
		int n, k;
		cin>>n>>k;
		int p = 0,v=0;
		loop{
			cout<<(i ^ p)<<endl;
			p ^= (i^p);
			cin >> v;
			if(v == 1) break;
		}
	}
}