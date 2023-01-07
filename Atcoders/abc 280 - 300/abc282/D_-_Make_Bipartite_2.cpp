#include <bits/stdc++.h>
using namespace std;

#define loop           	for (int i = 0; i < n; i++)
#define lop(i, n)      	for (int i = 0; i < n; i++)
#define lp(i, x, n)    	for (int i = x; i < n; i++)
#define pool		    for (int i = n-1; i >=0; i--)
#define returnn(x)  		{cout<<x<<'\n'; return;}
#define yes				return("YES")
#define no             	return("NO")
#define yesno(x)      	cout<<(x?"YES":"NO")<<'\n'
#define all(x)         	x.begin(), x.end()
#define sortall(x)    	sort(all(x))
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

template<typename T, typename V>
	void __print(const pair<T, V> &x)
		{cerr << '{'; __print(x.first);cerr<<',';__print(x.second);cerr<<'}';}
template<typename T>
	void __print(const T &x) 
		{int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
	void _print()
		{cerr << "]\n";}
template <typename T, typename... V>
	void _print(T t, V... v)
		{__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
vector<int> col;

bool isBipartite(int V,pi start, vector<int> adj[]){
    col.resize(V, -1);
    queue<pi> q; q.push(start);
	while (!q.empty()){
		pi p = q.front(); q.pop();
		int v = p.first, c = p.second;
		for (int j : adj[v]) {
			if (col[j] == c) return 0;
			if (col[j] == -1) {
				col[j] = (c) ? 0 : 1;
				q.push({ j, col[j] });
			}
		}
	}
    return 1;
}

void solve()
{
	int n,m; cin>>n>>m;
	vector<int> g[n];
	set<pi> st;
	pi start;
	lop(i,m) {
		int u,v; cin>>u>>v;
		u--,v--;
		if(u>v) swap(u,v);
		start = {u,v};
		st.insert(start);
		g[u].pb(v);
		g[v].pb(u);
	}
	if(isBipartite(n,start,g) == 0) returnn(0);
	int z = count(all(col),0), o = count(all(col),1);
	int total = (z*o);
	cout<<n*(n-1)-st.size()<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int tc = 1;
	while (tc--) solve();
	return 0;
}

//I, stunnerhash, hereby declare myself as the owner of this piece of shit code.