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
    vector<vector<char>> a(n,vector<char>(m));
    vector<vector<char>> ans(n,vector<char>(m,'.'));
    loop lop(k,m) cin>>a[i][k];
    loop{
        int u = 0, d = 0;
        lop(k,m){
            char c = a[i][k];
            u += c == 'U', d += c == 'D';
            if(c == 'U') ans[i][k] = (u%2?'W':'B');
            else if(c == 'D') ans[i][k] = (d%2?'B':'W');
        }    
        if(u%2 or d%2)returnn(-1); 
    }
    lop(k,m){
        int l = 0, r = 0;
        lop(i,n){
            char c = a[i][k];
            l += c == 'L', r += c == 'R';
            if(c == 'L') ans[i][k] = (l%2?'W':'B');
            else if(c == 'R') ans[i][k] = (r%2?'B':'W');
        }    
        if(l%2 or r%2)returnn(-1); 
    }
    loop {
        lop(k,m) cout<<ans[i][k]; cout<<endl;
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