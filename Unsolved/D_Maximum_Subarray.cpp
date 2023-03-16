#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)      	for (int i = 0; i < n; i++)
typedef vector<int>    	 vi;
typedef vector<long long> vl;

#define int long long
int maxi = 0, len;
void kadane(vector<int>a, int size, int x)
{
	rep(i,size) a[i] += 2*x;
    int max_so_far = INT_MIN, max_ending_here = 0,
       start =0, end = 0, s=0;
 
    for (int i=0; i< size; i++ )
    {
        max_ending_here += a[i];
 
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
 
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
	maxi = max_so_far;
	len = end- start+1;
}
void solve() {
	int n,k,x; cin>>n>>k>>x;
	vl a(n); rep(i,n)cin>>a[i];

	// manipulation
	if(x<0) k = n-k; x = abs(x); 
	rep(i,n) a[i] -= x;

	// prefix suffix
	vl p(n), s(n), pmax(n), smax(n);
	p[0] = a[0]; s[n - 1] = a[n - 1];
	rep(i,n-1) p[i+1] = p[i] + a[i+1];
	for(int i = n-2;i>=0;i--) s[i] = s[i+1] + a[i];
	
	// suffix max and prefix max
	pmax[n-1] = p[n-1]; smax[0] = s[0];
	rep(i,n-1) smax[i+1] = max(s[i+1],smax[i]);
	for(int i = n-2;i>=0;i--) pmax[i] = max(pmax[i+1], p[i]);

	// upto 20 size arrays 
	kadane(a,n,x);
	int ans = 0; if(len <= k) ans = maxi;
	cerr<<len<<' '<<maxi<<endl;
	// answer greater than 20 size	
	for(int i = 0;i<n-k;i++){
		if(i == 0) ans = max(ans,2*k*x + pmax[k]);
		else ans = max(ans, 2*k*x + (pmax[i+k] - p[i-1]) + (smax[i]-s[i]));
	}
	cout<<ans<<endl;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1; cin>>t;
	while (t--) solve();
	return 0;
}