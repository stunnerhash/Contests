#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t = 1;
	scanf("%d",&t);
	while (t--){
		int n, k;
		cin>>n>>k;
		
		int bit = 0, r = 0;
		for (int i = 0; i < n; i++){
			cout << (i ^ bit) << endl;
			cout.flush();

			cin >> r;
			bit ^= i ;
			if(r == 1) break;
			if (r == -1) exit(-1);
		}
	}
	return 0;
}