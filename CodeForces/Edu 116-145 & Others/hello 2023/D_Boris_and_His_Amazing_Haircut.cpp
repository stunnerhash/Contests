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

class segtree{
public:
	vector<int> tree;
	vector<int> v;
	int l,r,ind,val,n,segnull;
	segtree(int nn,vector<int> a){
		n = nn;
		tree.resize(4 * n);
		v = a;
		buildTree(0,n - 1,1);
		segnull = -1e9;//assign segnull
		//update comb and upd
	}
	inline int comb(const int &x,const int &y){
		return max(x,y);
	}
	inline void upd(int &x,const int &val){
		x = min(x,val);
	}
	void buildTree(int start,int end,int node){
		if(start == end){
			tree[node] = v[start];
			return ;
		}
		int mid = (start+end)/2;
		buildTree(start,mid,node*2);
		buildTree(mid+1,end,node*2+1);
		tree[node] = comb(tree[node*2],tree[node*2+1]);
	}
	void build(){
		buildTree(0,n - 1,1);
	}
	void updateTree(int start,int end,int node){
		if(start == end){
			upd(v[ind],val);
			upd(tree[node],val);
			return;
		}
		int mid = (start+end)/2;
		if(ind <= mid){
			updateTree(start,mid,node*2);
		}
		else{
			updateTree(mid+1,end,node*2+1);
		}
		tree[node] = comb(tree[node*2],tree[node*2+1]);
	}
	void update(int iind,int vval){
		ind = iind,val = vval;
		updateTree(0,n - 1,1);
	}
	int query(int start,int end,int node){
		if(end < l || start > r)
			return segnull;
		if(l <= start && end <= r){
			return tree[node];
		}
		int mid = (start+end)/2;
		int sol1 = query(start,mid,node*2);
		int sol2 = query(mid+1,end,node*2+1);
		return comb(sol1,sol2);
	}
	int query(int L,int R){
		l = L,r = R;
		return query(0,n - 1,1);
	}
};
void solve() {
	int n; cin>>n; vl a(n), b(n); loop cin>>a[i]; loop cin>>b[i];
	int m; cin>>m; map<int,int>c; lop(i,m){int x; cin>>x; c[x]++;}
	map<int, vector<int>> ind;
	loop  if (a[i] < b[i]) no
		else ind[b[i]].pb(i);

	segtree st(n,b);
	bool ok = 1;
	function<void(int,int)> recurse = [&](int l, int r){
		if(l>r or ok == 0) return;

		int mx = st.query(l,r), prev = l, need = 0;
		int id = lower_bound(ind[mx].begin(),ind[mx].end(),l) - ind[mx].begin();

		for(int i = id;i<ind[mx].size() and ind[mx][i]<=r; i++){
			if(a[ind[mx][i]] != b[ind[mx][i]]) need = 1;
            recurse(prev, ind[mx][i] - 1);
            prev = ind[mx][i] + 1;
		}
		recurse(prev,r);
		c[mx] -= need;
		if (c[mx] < 0) ok = 0;
	};
	recurse(0,n-1);
	yesno(ok);
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