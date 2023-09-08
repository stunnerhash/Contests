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

int coinchange(vector<int>& a, int v, int n, vector<vector<int> >& dp)
{
    if (v == 0) return dp[n][v] = 1;
    if (n == 0) return 0;
    if (dp[n][v] != -1) return dp[n][v];
    if (a[n - 1] <= v)  
		return dp[n][v] = coinchange(a, v - a[n - 1], n, dp) + coinchange(a, v, n - 1, dp);

    else return dp[n][v] = coinchange(a, v, n - 1, dp);
}
int factors(int n, int x,int k){
	map<int,int>m;
    while (n % 2 == 0) {
		m[n]++;
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2){
        while (n % i == 0) {
			if(i>x) return false;
			m[i++];
            n = n/i;
        }
    }
    if (n > 2) m[n]++;
	for(auto i:m) if(i.ff>x) return false; 
	if(k == 1) m[1]++;
	vi a;
	for(auto i:m) a.pb(i.ff);
	vvl dp(a.size()+1,vi (n+1));
	return coinchange(a,n,a.size(),dp);
}

void solve()
{
	int n, k;
	for(int i = 1;i<=n;i++){
		int ans = 0;
		int x = k;
		for(;x*(x+1)<=2*i;x++){
			int y = i-x;
			if(y == 0) {
				ans++;
				continue;
			}
			ans += factors(y,x,k);
		}
		cout<< ans<<' ';
	}
	cout<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	solve();
	return 0;
}

//I, stunnerhash, hereby declare myself as the owner of this piece of shit code.