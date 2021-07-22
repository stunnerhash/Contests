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

#define int long long
const int  N = 200005;

void Solve()
{
	int n; cin>>n;
	vi a(n+1),b(n+1),c(n+1);

	set<int> s1, s2;
	
	for(int i = 1; i <= n; ++ i) {
		cin>>a[i];
		s1.insert(i);
		s2.insert(i);
		b[i] = 0;
		c[i] = 0;
	}
	
	b[1] = c[1] = a[1];
	s1.erase(a[1]);
	s2.erase(a[1]);
	for(int i = 2; i <= n; ++ i)
		if(a[i] != a[i - 1])
		{
			s1.erase(a[i]);
			s2.erase(a[i]);
			b[i] = c[i] = a[i];
		}
	
	for(int i = 1; i <= n; ++ i)
	{
		if(!b[i]) {
			b[i] = *s1.begin();
			s1.erase(b[i]);
		}
		
		if(!c[i]) {
			auto it = s2.upper_bound(c[i - 1]);
			it --;
			c[i] = *it;
			s2.erase(c[i]);
		}
	}
	loop cout<<b[i+1]<<" ";
	cout<<endl;
	loop cout<<c[i+1]<<" ";
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