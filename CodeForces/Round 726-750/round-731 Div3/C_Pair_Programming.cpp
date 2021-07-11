#include <bits/stdc++.h>
using namespace std;

#define loop           	for (int i = 0; i < n; i++)
#define lop(i, n)      	for (int i = 0; i < n; i++)
#define lp(i, k, n)    	for (int i=k;k < n?i < n: i>n;k < n? i+=1: i-=1)
#define trav(a) 		for (auto it = a.begin();  it != a.end();  it++)
#define dbg(x)         	{cout<<#x<<"="<<x<<endl;cerr<<#x<<"="<<x<<endl;}
#define yes(x)      	cout<<(x?"YES\n":"NO\n")
#define no             	{cout<< "NO\n"; return;}
#define clr(x)         	memset (x, 0, sizeof(x))
#define all(x)         	x.begin(), x.end()
#define sortall(x)     	sort(all(x))
#define ll             	long long
#define pb             	push_back
#define mp             	make_pair
#define INF            	(int) 1e9
#define mod            	1000000007	
#define ss             	second
#define ff             	first
#define endl           	"\n"
typedef pair<int, int> 	pi;
typedef pair<ll, ll>   	pl;
typedef vector<int>    	vi;
typedef vector<ll>     	vl;
typedef vector<pi>     	vpi;
typedef vector<vi>     	vvi;


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

// #define int long long
const int  N = 200005;

void Solve()
{
	int k, n, m;
	cin>>k>>n>>m;
	vi a(n);
	vi b(m);
	vi ans;
	loop cin>>a[i];
	lop(i, m) cin >> b[i];
	int i = 0, o = 0;
	while(i<n or o<m){
		int ok = 1 , ok2 = 1;

		if(i<n)
		{
			if( a[i] == 0){
				ans.pb(a[i]);
				i++;
				k++;
			}
			else if( a[i] >0) {
				if(a[i]<=k) {
					ans.pb(a[i]);
					i++;
				}
				else  ok = 0; 
			}	
		}
		else ok  = 0;

		if(o<m){
			if(b[o] == 0 ) {
				ans.pb(b[o]);
				o++;
				k++;
			}
			else if (b[o]){
				if(b[o]<=k){
					ans.pb(b[o]);
					o++;
				}
				else ok2 = 0; 
			}
		}
		else ok2 = 0;
		if( ok ==0  and ok2  == 0){
			cout<<-1<<endl;
			return;
		}
	}
	trav(ans) cout<<*it<<" ";
	cout<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int Testcase = 1;
	cin>>Testcase;

	while (Testcase--) Solve();
	 return 0;
}