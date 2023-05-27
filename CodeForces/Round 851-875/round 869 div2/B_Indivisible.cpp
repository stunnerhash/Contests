#include <bits/stdc++.h>
using namespace std;


int main()
{
	int t = 1;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		if(n == 1) {
			cout<<1<<endl;
			continue;
		}
		if(n%2  or ((n*(n+1))/2) % n == 0){
			cout<<-1<<endl;
			continue;
		}
		for(int i = 1;i<=n;i+=2)
			cout<<i+1<<' '<<i<<' ';
		cout<<endl;
	}
	return 0;
}
