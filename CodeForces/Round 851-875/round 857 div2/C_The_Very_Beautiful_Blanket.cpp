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

void solve() {
	int n,m; cin>>n>>m;
	int x = n+n%2, y = m+ m%2;
	vector<vector<int>>a(x,vector<int>(y));
	int cnt = 0;
	int val = 0;
	// 0b10011000001100
	//   00011000001101
	
	// 0b10100000001100
	//   00100000001101

	// 0b10101000001100
	//   00101000001101
	//   0b101000010001
	// 0b10101000010100
	for(int i = 0;i<x;i+=2){
		int 
		val = i*(1<<((int)log2(x)+1));
		for(int k = 0;k<y;k+=2){
			a[i][k] =  val+ cnt++;
			a[i][k+1] = cnt++;
			a[i+1][k] = cnt++;
			a[i+1][k+1] =cnt++;
		}
	}
	cout<<n*m<<endl;
	loop {
		lop(k,m) cout<<a[i][k]<<' ';
		cout<<endl;
	}
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
// If it works... don't touch it.