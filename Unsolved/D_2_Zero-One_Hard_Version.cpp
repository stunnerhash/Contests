#include <bits/stdc++.h>
using namespace std;

#define loop           	for (int i = 0; i < n; i++)
#define lop(i, n)      	for (int i = 0; i < n; i++)
#define lp(i, k, n)    	for (int i=k;k < n?i < n: i>n;k < n? i+=1: i-=1)
#define trav(a) 		for (auto it = a.begin();  it != a.end();  it++)
#define yesno(x)      	cout<<(x?"YES\n":"NO\n")
#define yes				{cout<< "YES\n"; return;}
#define no             	{cout<< "NO\n"; return;}
#define return(x)       {cout<<x<<'\n';return;}
#define all(x)         	x.begin(), x.end()
#define travauto(a)		for (auto& it:a)
#define sortall(x)    	sort(all(x))
#define ll             	long long
#define pb             	push_back
#define ss             	second
#define ff             	first
#define endl           	"\n"
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
	int n,x,y; cin>>n>>x>>y;
	string a,b; cin>>a>>b;
	int ca = count(all(a),'0'), cb = count(all(b),'0');
	if((ca%2) != (cb)%2){
		cout<<-1<<endl;
		return;
	}
	vl ar(n); loop ar[i] = (a[i]!=b[i]);
	if(x>=y){
		int sum = 0; loop sum += ar[i];
		int ans = 0;
		if(sum == 2){
			bool ok = 0;
			for(int i = 0;i<n-1;i++)
				if(ar[i] == ar[i+1] and ar[i] == 1) ok = 1;

			if(ok) return(min(x,2*y));
			return (y);
		}
		return(y*sum/2);
	}

	vl dif,f(5005);
	loop if(a[i]!=b[i]) dif.pb(i);
	if(dif.size() == 0) return(0);
	
	f[0] = f[1] = 0;
	for(int i=2;i<=dif.size();i++) {
		f[i] = f[i - 2] + min(x * (dif[i - 1] - dif[i - 2]), y);
		if (i % 2 == 0) f[i] = min(f[i], f[i - 1] + y);
		else f[i] = min(f[i], f[i - 1]);
	}
	cout<<f[dif.size()]<<endl;
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