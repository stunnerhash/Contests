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
int n,q; vl seg;

void update(int id, int val, int i = 0, int l = 0, int r = n) {
	if(id<l or id>r) return;
	if(l == r){
		if(id == l) seg[i] += val;
		return;
	}
	int mid = (l+r)/2;
	update(id, val, 2 * i + 1, l, mid);
	update(id, val, 2 * i + 2, mid + 1, r);
	seg[i] = seg[i * 2 + 1] + seg[i * 2 + 2];
}
int query(int L, int R, int i = 0, int l = 0, int r = n){
	if (r < L or l > R) return 0;
	if (l >= L and r <= R) return seg[i];
	int mid = (l + r) / 2;
	return query(L, R, 2 * i + 1, l, mid) + query(L, R, 2 * i + 2, mid + 1, r);
}

signed main() {
	//input
	cin>>n>>q;
	vl a(n); loop cin>>a[i];
	
	// segment tree
	seg.resize(4*(n+1),0);

	while(q--){
		int type; cin>>type;
		if(type == 1){
			int left, right, val;cin>>left>>right>>val;
			update(left-1,val);
			update(right,-val);
			}
		else {
			int k; cin>>k;
			cout<<a[k-1]+query(0,k-1)<<endl;
		}
	}
}
// If it works... don't touch it.