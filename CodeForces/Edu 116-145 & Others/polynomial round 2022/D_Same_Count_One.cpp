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

void solve()
{
	int n,m,cnt = 0; cin>>n>>m;
	vvi a(n,vi(m));
	loop {
		lop(k,m) cin>>a[i][k];
		cnt += count(all(a[i]), 1);
	}
	if(cnt%n) returnn(-1);
	int tar = cnt/n;
	vi v(n); loop v[i] = count(all(a[i]),1)-tar;
	vector<vector<int>> ans;
	for(int k = 0;k<m;k++){
		vi sub,add;
		loop{
			if(a[i][k] == 1 and v[i] >0) sub.pb(i);
			else if(a[i][k] == 0 and v[i]<0) add.pb(i);
		}
		int size = min(sub.size(),add.size());
		lop(i,size){
			v[sub[i]]--;
			v[add[i]]++;
			ans.pb({sub[i]+1,add[i]+1,k+1});
		}	
	}
	cout<<ans.size()<<endl;
	for(auto i:ans) cout<<i[0]<<' '<<i[1]<<' '<<i[2]<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int tc = 1;
	cin>>tc;

	while (tc--) solve();
	return 0;
}

//I, stunnerhash, hereby declare myself as the owner of this piece of shit code.