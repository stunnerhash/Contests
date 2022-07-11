#include <bits/stdc++.h>
using namespace std;

#define loop 			for (int i=0;i<n;i++)
#define all(x)	 		x.begin(), x.end()
#define sortall(x) 		sort(all(x))
#define int 			long long 

typedef pair<int, int> 	pi;
typedef vector<int> 	vi;
typedef vector<pi> 		vpi;


void solve(){
	int n ; cin>>n;
	vi a(n), b(n);
	loop cin >> a[i] >> b[i];
	sortall(a);
	sortall(b);
	cout<<(a[n/2]-a[(n-1)/2]+1)*(b[n/2]-b[(n-1)/2]+1)<<endl;
}
int main()
{
	int testcase = 1;
	cin>>testcase;
	while (testcase--)solve();
}