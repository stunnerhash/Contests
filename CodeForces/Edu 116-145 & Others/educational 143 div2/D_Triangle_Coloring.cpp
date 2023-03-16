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
const ll mod  = 998244353;
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
template <ll mod = mod>
struct modint {
	ll val;
	modint() : val(0) {}
	modint(ll a) : val(a) { val += mod; if(val >= mod) val -= mod; }
	void operator = (modint a) { val = a.val; }
	bool operator == (modint a) { return val == a.val; } 
	bool operator != (modint a) { return val != a.val; }
	inline modint& operator += (modint a) { val = val + a.val; if(val >= mod) val-=mod; return *this; }
	inline modint& operator -= (modint a) { val = val - a.val + mod; if(val >= mod) val -= mod; return *this; }
	inline modint& operator *= (modint a) { val = (val*a.val)%mod; return *this; }
	friend modint operator + (modint a, modint b) { return (a += b); }
	friend modint operator - (modint a, modint b) { return (a -= b); } 
	friend modint operator * (modint a, modint b) { return (a *= b); }
	friend modint operator ^ (modint a, ll b) { modint res = 1; for (; b; b >>= 1) { if (b & 1)res*=a; a*=a; } return res; }
	friend modint operator / (modint num, modint den) { den = den ^ (mod-2); return (num*den); }
	friend ostream & operator << (ostream &out, modint a) { out << a.val; return out; }
	friend istream & operator >> (istream &in, modint& a) { in >> a.val; return in; }
};

using mint = modint<mod>;

unsigned long long power(unsigned long long x, int y, int p) {
    unsigned long long res = 1; // Initialize result
    x = x % p; // Update x if it is more than or
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
unsigned long long modInverse(unsigned long long n,  int p) {
    return power(n, p - 2, p);
}
  
unsigned long long ncr(unsigned long long n, int r, int p) { 
    if (n < r) return 0;
    if (r == 0) return 1;
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
void solve() {
	int n; cin>>n; n/=3;
	vector<vl> a(n,vl(3));
	mint ans = ncr(n,n/2,mod);
	loop cin>>a[i][0]>>a[i][1]>>a[i][2];
	loop{
		sortall(a[i]);
		if(a[i][0] == a[i][1]){
			if(a[i][1] == a[i][2]) ans *=3; // teeno equal 
			else ans *=2;// first two equal 
		}
	}
	cout<<ans<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int tc = 1;

	while (tc--) solve();
	return 0;
}
// If it works... don't touch it.