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
#define mod            	INF + 7
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
const int  N = 1e5+5;

void Solve()
{
	int n;
	cin>>n;
	vvi a(n,vi(n));
	loop{
		int x; cin>>x;
		a[i][i] = x;
	}
	for(int i = n-1;i>=0;i--){
		int t = a[i][i]-1 ;
		int x = i,y = i;
		while(t--){
			if(x+1<n and a[x+1][y] == 0){
				x++;
				a[x][y] = a[i][i];
			}
			else if(y-1>=0 and a[x][y-1] == 0 ){
				y--;
				a[x][y] = a[i][i];
			}
		}
	}
	loop {
		lop(k,n) if(a[i][k])cout<<a[i][k]<<" ";
		else break;
		cout<<endl;
	}
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int Testcase = 1;

	while (Testcase--) Solve();
	 return 0;
}