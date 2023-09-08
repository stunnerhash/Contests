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

struct dsu {
	vector<int> p,r;
	dsu(int n) {
		for(int i = 0;i<=n;i++){
			p.pb(i); r.pb(0);
		}
	}
	int get(int a) {
		return (p[a] = (p[a]==a)?a:get(p[a]));
	}
	void uni(int a, int b) {
		a = get(a); b = get(b);
		if(a==b) return;
		if(r[a]==r[b]) r[a]++;
		if(r[a] < r[b]) swap(a,b);
		p[b] = a;
	}
};

int n; vi vis,a;
map<int,int> mp;
void dfs(int node, int cnt, struct dsu& one){
	if(vis[node]) return;
	vis[node] = cnt;
	while(node< n and node>=0){
		int par = node;
		node = node+ a[node];	
		if(node < n and node >= 0 and  vis[node]>0){ one.uni(vis[node], vis[par]); break;}
		vis[node] = cnt;
	}
	if(node >=n or node < 0) mp[cnt] = 1; 
}

void solve() {
	
	int cnt = 0; cin>>n;
	a.resize(n,0); vis.resize(n,0); mp.clear(); loop cin>>a[i];
	loop vis[i] = 0;
	struct dsu one(n);
	loop if (!vis[i]) dfs(i, ++cnt, one);

	loop {
		int par = one.get(vis[i]);
		if(mp[par] == 1) cout<<i<<' ';
	}
	cout<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int tc = 1;
	cin>>tc;

	while (tc--) solve();
	return 0;
}
// If it works... don't touch it.