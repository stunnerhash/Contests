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
 
void solve() {
	int n; cin>>n; vl a(n); loop cin>>a[i]; sortall(a);
    vector<mint> pot(n+1); pot[0] = 1; loop pot[i+1] = pot[i] * 2;
    mint ans = 0;
    loop {
        lop(j,i) {
            ll dist = a[i] - a[j];
            ll n1 = a.end() - lower_bound(all(a), a[i] + dist);
            ll n2 = lower_bound(all(a), a[j] - dist) - a.begin();
            ans += pot[n1 + n2];
        }
    }
	cout<<ans<<endl;
}

signed main() {
	solve();
	return 0;
}
// If it works... don't touch it.