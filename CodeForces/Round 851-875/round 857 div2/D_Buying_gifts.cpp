#include <bits/stdc++.h>
using namespace std;

#define loop           	for (int i = 0; i < n; i++)
#define lop(i, n)      	for (int i = 0; i < n; i++)
#define lp(i, x, n)    	for (int i = x; i < n; i++)
#define pool            for (int i = n-1; i >=0; i--)
#define returnn(x)      {cout<<x<<'\n'; return;}
#define yes             returnn("YES")
#define no              returnn("NO")
#define yesno(x)        cout<<(x?"YES":"NO")<<'\n'
#define all(x)         	x.begin(), x.end()
#define sortall(x)      sort(all(x))
#define ll             	long long
#define pb             	push_back
#define ss             	second
#define ff             	first
#define endl           	'\n'
typedef pair<int, int> 	pi;
typedef pair<ll, ll>   	pl;
typedef vector<int>    	vi;
typedef vector<ll>     	vl;
typedef vector<pi>     	vpi;
typedef vector<vi>     	vvi;
const ll mod  = 1000000007;
const ll inf  =	1e9;
const ll linf =	1e18;

void __print(int x)    	        {cerr << x;}
void __print(long x)   	        {cerr << x;}
void __print(float x)  	        {cerr << x;}
void __print(double x) 	        {cerr << x;}
void __print(unsigned x)       	{cerr << x;}
void __print(long long x)      	{cerr << x;}
void __print(long double x)    	{cerr << x;}
void __print(unsigned ll x)    	{cerr << x;}
void __print(unsigned long x)  	{cerr << x;}
void __print(const char *x)    	{cerr << '"' << x << '"';}
void __print(const string &x)  	{cerr << '"' << x << '"';}
void __print(char x)           	{cerr << '\''<< x <<'\'';}
void __print(bool x)           	{cerr <<(x?"true":"false");}

template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first);cerr<<',';__print(x.second);cerr<<'}';}
template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";} void _print() {cerr << "]\n";}
template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
int dif(vector<int>v){
	return abs(v[0]-v[1]);
}
void solve() {
	int n; cin>>n;
	vector<vector<int>> a(n,vector<int>(2));

	loop cin>>a[i][0]>>a[i][1];
	int fmax = 0, smax = 0, fmin = 1e9, smin = 1e9;
	loop fmax = max(fmax,a[i][0]),fmin = min(fmin,a[i][0]);
	loop smax = max(smax,a[i][1]),smin = min(smin,a[i][1]);
	vector<int> ia, ib;
	int fmincount = 0,smincount = 0;
	int fminid, sminid;
	loop if (a[i][0] == fmax) ia.pb(i);
		else if (a[i][0] == fmin)  fminid = i, fmincount++;
	loop if (a[i][1] == smax) ib.pb(i);
		else if (a[i][0] == smin)  sminid = i, smincount++;
	bool ftake = (fmincount >0), stake = (smincount>0);
	int fid = ia[0], sid = ib[0];
	lop(i,ia.size()){
		int id = ia[i];
		if(dif(a[fid])<dif(a[id])) fid = id;
	}
	lop(i,ib.size()){
		int id = ib[i];
		if(dif(a[sid])< dif(a[id])) sid = id;
	}

	int ans = 2e9;
	loop {
		if(i == fid or (ftake == 0 and sminid == i)) continue;
		ans = min(ans,abs(a[i][1]-a[fid][0]));
	}
	loop {
		if(i == sid or (stake == 0 and fminid == i)) continue;
		ans = min(ans,abs(a[i][0]-a[sid][1]));
	}
	cout<<ans<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int tc = 1;
	cin>>tc;

	while (tc--) solve();
	return 0;
}
