#include <bits/stdc++.h>
using namespace std;

#define loop           	for (int i = 0; i < n; i++)
#define lop(i, n)      	for (int i = 0; i < n; i++)
#define lp(i, x, n)    	for (int i = x; i < n; i++)
#define pool		    for (int i = n-1; i >=0; i--)
#define return(x)  		{cout<<x<<'\n'; return;}
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
int power(int x, int y) { 
	int res = 1; 
	x = x % mod; 
	while (y > 0) { 
		if (y & 1) (res *= x) %= mod; 
		y = y>>1; 
	   (x *= x) %= mod; 
	}
	return res;
}
void solve()
{
	int n; cin>>n;
	string s; cin>>s;
	
	int id = -1; loop if(s[i] == '1'){ id = i; break;}
	int correct = 0;
	if(count(all(s),'0') == n or count(all(s),'1') == n) return(0)
	int idx = -1;
	for(int i = id;i<n;i++) if(s[i] == '0'){idx = i;break;}


	string a = s.substr(id,n-id);
	string b = s.substr(max(0ll,idx-id),n-id);
	if(id == 0){
		a = s.substr(id,n-id-idx);
		b = s.substr(0+idx,n-id-idx);
	}
	vl ans(a.size());
	for (int i = 0; i < a.size(); i++) 
		ans[i] = (a[i] != b[i]);
	debug(a,b);
	reverse(all(ans));
	int res = 0;
	lop(i, ans.size()) 
		res = (res + ans[i]*power(2, i)) % mod;
	cout<<res<<endl;
}	

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int tc = 1;
	cin>>tc;

	while (tc--) solve();
	return 0;
}

//I, stunnerhash, hereby declare myself as the owner of this piece of shit code.