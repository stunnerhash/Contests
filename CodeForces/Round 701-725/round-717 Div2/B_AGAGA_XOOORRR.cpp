#include <bits/stdc++.h>
using namespace std;

#define loop           	for(int i = 0; i < n; i++)
#define lop(i, n)      	for(int i = 0; i < n; i++)
#define lp(i, k, n)    	for(int i=k;k < n?i < n: i>n;k < n? i+=1: i-=1)
#define dbg(x)         	{cout<<#x<<"="<<x<<endl;cerr<<#x<<"="<<x<<endl;}
#define yes(flag)      	cout<<(flag?"YES":"NO")<<endl;
#define no             	{cout << "NO" <<endl; return;}
#define clr(x)         	memset(x, 0, sizeof(x))
#define trav(a)        	for (auto it : a)
#define all(x)         	x.begin(),x.end()
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
	int n ;
	cin>>n;
	vi a(n);
	loop cin>>a[i];
	int bit=0;
	loop bit^= a[i];
	if(bit == 0 ){
		yes(1)
		return;
	}
	int i,store=0;
	bool x=0,y =0;
	for(i = 0;i<n-2;i++){
		store^= a[i];
		if(store == bit){
			x = true;
			break;
		}
	}
	for(i = i+1;i<n-1;i++){
		store^= a[i];
		if(store == 0){
			y = true;
			break;
		}
	}
	yes(x and y);
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int Testcase = 1;
	cin>>Testcase;

	while (Testcase--) Solve();
	 return 0;
}