#include <bits/stdc++.h>
using namespace std;

#define loop           	for (int i = 0; i < n; i++)
#define lop(i, n)      	for (int i = 0; i < n; i++)
#define lp(i, x, n)    	for (int i = x; i < n; i++)
#define pool		    for (int i = n-1; i >=0; i--)
#define returnn(x)  		{cout<<x<<'\n'; return;}
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
struct mint {
	int val; mint  (int _= 0) { val = _ % mod;  	  }
	 mint operator+ (mint oth) { return val + oth.val;}
	 mint operator* (mint oth) { return 1LL * val * oth.val; }
	 mint operator- (mint oth) { return val - oth.val + mod; }
	 void operator+=(mint oth) { val = (mint(val) + oth).val; }
	 void operator-=(mint oth) { val = (mint(val) - oth).val; }
	 void operator*=(mint oth) { val = (mint(val) * oth).val; }
};
vector<int> get_primes(int n) {
    int d = 2;
    vector<int> ans;
    while (d * d <= n) {
        bool ok = false;
        while (n % d == 0) {
            n /= d;
            ok = true;
        }
        if (ok) ans.pb(d);
        d++;
    }
    if (n != 1) ans.pb(n);
    return ans;
}
void solve(){
	int n, m; cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	bool ok = true;
	for (int i = 2; i <= n; ++i)
		if (a[i - 1] % a[i] != 0) {
			ok = false;
			break;
		}

	if (!ok) returnn (0)
	vector<int> factori = get_primes(a[1]);
	map<pair<int, int>, int> calc;
	for (int i = 2; i <= n; ++i) calc[{a[i - 1], a[i]}];

	for (auto &i : calc) {
		int left = i.ff.ff/ i.ff.ss;
		int till = m / i.ff.ss;
		vector<int> left_primes;
		for (auto ii : factori) if (left % ii == 0) left_primes.pb(ii);
		int sz = (int)left_primes.size();

		for (int mask = 0; mask < (1 << sz); ++mask) {
			int prod = 1, cnt = 0;
			for (int j = 0; j < sz; ++j)
				if (mask & (1 << j)) {
					prod *= left_primes[j];
					cnt++;
				}
			if (cnt % 2 == 0) i.ss += till / prod;
			else i.ss -= till / prod;
		}
	}

	mint ans = 1;
	for (int i = 2; i <= n; ++i) ans = ans * calc[{a[i - 1], a[i]}];

	cout << ans.val << '\n';
}

signed main() {
    int q; cin >> q;
    while (q--) solve();
	return 0;
}