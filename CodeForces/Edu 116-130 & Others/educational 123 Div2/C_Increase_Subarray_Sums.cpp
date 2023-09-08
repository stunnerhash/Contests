#include <bits/stdc++.h>
using namespace std;

// #define loop           	for (int i = 0; i < n; i++)
#define lop(i, n)      	for (int i = 0; i < n; i++)
#define lp(i, k, n)    	for (int i=k;k < n?i < n: i>n;k < n? i+=1: i-=1)
#define trav(a) 		for (auto it = a.begin();  it != a.end();  it++)
#define dbg(x)         	{cout<<#x<<"="<<x<<endl;cerr<<#x<<"="<<x<<endl;}
#define yes(x)      	cout<<(x?"YES\n":"NO\n")
#define no             	{cout<< "NO\n"; return;}
#define clear(x)       	memset (x, 0, sizeof(x))
#define all(x)         	x.begin(), x.end()
#define sortall(x)    	sort(all(x))
#define ll             	long long
#define pb             	push_back
#define mp             	make_pair
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
// template<typename T> inline void printlist(T& a) { for(auto i : a) 
// 	cout << i << " "; cout << endl; }


#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define loop(i,a,b)           for(int i=(int)a;i<(int)b;++i)
const ll INF = 1e18;

inline ll po(ll a, ll b) { ll res = 1; for (; b; b >>= 1) { if (b & 1)res = res * a; a = a * a; }return res; }
inline ll gcd (ll a, ll b) { ll r; while(b) { r = a%b; a=b; b=r; } return a; }

template<typename T> inline void printlist(T& a) { for(auto i : a) cout << i << " "; cout << endl; }

#define int long long
void Solve() {
    int n,x; cin>>n>>x;
    vector<int> a(n+1); lp(i,1,n+1) cin>>a[i];
    lp(i,1,n+1) a[i] += a[i-1];
    vector<int> mx(n+1, -linf); mx[0] = 0;
    lp(k,1,n+1) 
        lp(i,k,n+1) mx[k] = max(mx[k], a[i] - a[i-k]);

    vector<int> ans(n+1, -linf);
    lp(k,0,n+1) 
        lp(i,0,n+1) 
            ans[k] = max(ans[k], mx[i] + min((ll)i,(ll)k)*x);
    printlist(ans);
}


signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int Testcase = 1;
	cin>>Testcase;

	while (Testcase--) Solve();
	return 0;
}