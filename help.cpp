#include <bits/stdc++.h>
using namespace std;

#define dbg(x)         {cout<<#x<<"="<<x<<endl;cerr<<#x<<"="<<x<<endl}
#define lp(i, k, n)    for(int i=k;k < n?i < n: i>n;k < n? i+=1: i-=1)
#define yes(flag)      cout<<(flag?"YES":"NO")<<endl;
#define no             {cout << "NO" <<endl; return;}
#define loop           for(int i = 0; i < n; i++)
#define lop(i, n)      for(int i = 0; i < n; i++)
#define clr(x)         memset(x, 0, sizeof( x ) )
#define all(x)         x.begin(),x.end()
#define trav(a)        for (auto it : a)
#define sortall(x)     sort( all ( x ) )
#define ll             long long
#define pb             push_back
#define mp             make_pair
#define INF            (int) 1e9
#define mod            INF + 7
#define ss             second
#define ff             first
#define endl           "\n"
typedef pair<int, int> pi;
typedef pair<ll, ll>   pl;
typedef vector<int>    vi;
typedef vector<ll>     vl;
typedef vector<pi>     vpi;
typedef vector<vi>     vvi;

void __print(int x)            {cerr << x;}
void __print(long x)           {cerr << x;}
void __print(float x)          {cerr << x;}
void __print(double x)         {cerr << x;}
void __print(unsigned x)       {cerr << x;}
void __print(long long x)      {cerr << x;}
void __print(long double x)    {cerr << x;}
void __print(unsigned ll x)    {cerr << x;}
void __print(unsigned long x)  {cerr << x;}
void __print(const char *x)    {cerr << '"' << x << '"';}
void __print(const string &x)  {cerr << '"' << x << '"';}
void __print(char x)           {cerr << '\''<< x <<'\'';}
void __print(bool x)           {cerr <<(x?"true":"false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first);cerr<<',';__print(x.second);cerr<<'}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int  N = 1e5+5;
int solve()
{
	int n,l,r; cin>>n>>l>>r;
    vector<vector<int>> dp(n, vector<int>(r-l+1, 0));
    int ans = 0;
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    for (int i = 1; i < dp[0].size(); i++) 
        dp[0][i] = dp[0][i - 1] + 1;

    ans = dp[0][r - l];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < dp[0].size(); j++) 
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        ans += dp[i][r - l];
    }
    return ans;
}

void Solve()
{
	
	// int n; cin>>n;
	// vector<int> a(n); for(int i =0;i<n;i++) cin>>a[i];
	// vector<int> suf(n);
	// suf[n-1] = a[n-1];
	// for(int i = n-2;i>=0;i--) suf[i] = max(suf[i+1],a[i]);
	// int ans = 0;
	// for(int i = 0;i<n;i++) ans = max(ans,suf[i] - a[i]);
	// cout<<ans<<endl;
}


signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int Testcase = 1;

	while (Testcase--) Solve();
	return 0;
}

//by stunnerhash