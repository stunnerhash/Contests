#include <bits/stdc++.h>
using namespace std;

#define loop           	for (int i = 0; i < n; i++)
#define lop(i, n)      	for (int i = 0; i < n; i++)
#define lp(i, k, n)    	for (int i=k;k < n?i < n: i>n;k < n? i+=1: i-=1)
#define trav(a) 		for (auto it = a.begin();  it != a.end();  it++)
#define yesno(x)      	cout<<(x?"YES\n":"NO\n")
#define yes				{cout<< "YES\n"; return;}
#define no             	{cout<< "NO\n"; return;}
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
#define return(x) {cout<<x<<endl;return;}
#define mp make_pair
void solve()
{
	int n; cin>>n;
	vi aa, a(n); loop cin>>a[i];
	loop if(a[i]) aa.pb(i);
	if(aa.size()%2) return (-1);

	vpi ans;
	for (int i = 0;i<aa.size(); i+=2) {
		int l = aa[i], r = aa[i+1], sign = (r-l)%2?1:-1;
		if(a[l] != sign*a[r]){
			ans.pb({l + 1, l + 1});
			ans.pb(sign == 1? mp(r + 1, r + 1):mp(l + 2, r + 1));
		}
		else ans.pb({l+1,r+1});
	}

	int x = ans.size();
	if(x == 0) { cout<<1<<endl<<1<<' '<<n<<endl; return; }
	if(ans[0].ff   > 1) ans.pb({1,ans[0].ff-1});
	if(ans[x-1].ss < n) ans.pb({ans[x-1].ss+1,n});
	for (int i = 0; i < x - 1; i++)
		if (ans[i].ss + 1 <= ans[i + 1].ff - 1)
			ans.pb({ans[i].ss + 1, ans[i+1].ff - 1});

	sortall(ans);
	cout<<ans.size()<<endl;
	for(auto i:ans) cout<<i.ff<<' '<<i.ss<<endl;
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