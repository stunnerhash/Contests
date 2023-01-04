#include <bits/stdc++.h>
using namespace std;

#define loop           	for (int i = 0; i < n; i++)
#define lop(i, n)      	for (int i = 0; i < n; i++)
#define lp(i, x, n)    	for (int i = x; i < n; i++)
#define pool		    for (int i = n-1; i >=0; i--)
#define yes				return("YES")
#define no             	return("NO")
#define yesno(x)      	cout<<(x?"YES":"NO")<<'\n'
#define all(x)         	x.begin(), x.end()
#define sortall(x)    	sort(all(x))
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

int mod;
int fac[5005],invfact[5005];

int power(int x, int y) { 
    int res = 1; 
    x = x % mod; 
    while (y > 0) { 
        if (y & 1) res = (res * x) % mod; 
        y = y >> 1; 
        x = (x * x) % mod; 
    } 
    return res; 
} 
int	 modInverse(int n) { 
    return power(n, mod - 2);
} 
void ini() {
    fac[0] = 1, invfact[0] = 1; 
    for (ll i = 1; i < 5005 ; i++){ 
        fac[i] = (fac[i - 1] * i) % mod;
        invfact[i] = modInverse(fac[i]);
    } 
}
int ncr(int n, int r){
    if (n<r) return 0;
    if (r==0 or r==n) return 1; 
    return ((fac[n]*invfact[r]%mod) * invfact[n - r]) % mod;  
}

void solve()
{
    int n; cin >> n >> mod;
    int ans = 0;
    ini();
    for(int x=0 ; x<(n+1)/2 ; ++x){
        int must= (n-(x+1));
        int optional = max(x-1,0ll);
        int last = n/2+x - (n+1)/2 + 1;
        for(int s=0 ; s<=optional ; ++s){
            ans += ((ncr(optional,s)*fac[must +s-1])%mod*last)%mod;
            ans %= mod;
        }
    }
    ans = (ans*n)%mod;
    cout << ans << endl;
    return;    
}

 
signed main() {
	solve();
	return 0;
}