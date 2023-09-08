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
		segnull = 0;//assign segnull
		//update comb and upd
	}
	inline int comb(const int &x,const int &y){
		return x + y; 
	}
	inline void upd(int &x,const int &val){
		x += val;
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
	int n; cin>>n; vi a(n), b(n);
	loop cin >> a[i]; loop cin >> b[i];
	vi pre(n); pre[0] = b[0]; 
	lop(i, n-1) pre[i+1] = pre[i] + b[i+1];
	vi drink(n);
	vl tp(n+1); segtree seg(n+1,tp);
	vl ans(n);
	loop{
		int q = a[i];
		if(i>0) q+= pre[i-1];
		int id = lower_bound(all(pre), q) - pre.begin()-1;
		drink[i] = id;
		int curr = (i>0? pre[i-1]: 0);
		debug(q, id, pre[id], curr);
		if(pre[id]-pre[i] == a[i]){
			seg.update(i,1);
			seg.update(id+1,-1);
		}
		else {
			seg.update(i,1);
			seg.update(id,-1);
			int preprev = (i>0? pre[id]:0);
			ans [id] += a[i] - (preprev - curr);
		}
	}
	// loop cerr<<seg.query(i,i)<<' '; cerr<<endl;
	// loop ans[i] += b[i]*seg.query(i,i);
	loop cout<<ans[i]<<" \n"[i==n-1];
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int tc = 1;
	cin>>tc;

	while (tc--) solve();
	return 0;
}
// If it works... don't touch it.