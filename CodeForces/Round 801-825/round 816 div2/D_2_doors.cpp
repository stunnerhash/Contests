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

void solve()
{
	int n,q; cin >> n >> q;
    vi ans(n,(1ll<<30)-1);
    vector<vpi> adj(n);    
 
    for(ll i=0 ; i<q ; ++i){
        ll x,y,w; cin >> x >> y >> w; x--,y--;
        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }
 
    for(ll bit=0 ; bit<30 ; ++bit){
        for(ll i=0 ; i<n ; ++i){
            for(auto x : adj[i])
                if( ((x.ss>>bit)&1ll) == 0 )
                    ans[i] &= ~(1ll << bit);
		}
        // now check for leftover 1's and try to make them 0
        for(ll i=0 ; i<n ; ++i){
            bool canbezero = true;
            if( ((ans[i]>>bit)&1ll))
                for(auto x : adj[i])
                    if(x.ff == i or ((ans[x.first]>>bit)&1ll) == 0){
                        canbezero = false;
                        break;
                    }
            if(canbezero) ans[i] &= ~(1ll << bit);    
        }
    }
	loop cout<<ans[i]<<" \n"[i==n-1];
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int tc = 1;

	while (tc--) solve();
	return 0;
}

//I, stunnerhash, hereby declare myself as the owner of this piece of shit code.