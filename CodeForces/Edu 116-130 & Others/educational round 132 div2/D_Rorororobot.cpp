#include <bits/stdc++.h>
using namespace std;

#define loop           	for (int i = 0; i < n; i++)
#define lop(i, n)      	for (int i = 0; i < n; i++)
#define lp(i, k, n)    	for (int i=k;k < n?i < n: i>n;k < n? i+=1: i-=1)
#define trav(a) 		for (auto it = a.begin();  it != a.end();  it++)
#define dbg(x)         	{cout<<#x<<"="<<x<<endl;cerr<<#x<<"="<<x<<endl;}
#define yes(x)      	cout<<(x?"YES\n":"NO\n")
#define no             	{cout<< "NO\n"; return;}
#define clear(x)       	memset (x, 0, sizeof(x))
#define all(x)         	x.begin(), x.end()
#define sortall(x)    	sort(all(x))
#define ll             	long long
#define pb             	push_back
#define mp             	make_pair
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

int getMid(int s, int e) {
    return s + (e - s) / 2;
}
int MaxUtil(int* st, int ss, int se, int l, int r, int node)
{
    if (l <= ss && r >= se) return st[node];
    if (se < l || ss > r) return -1;
    int mid = getMid(ss, se);
    return max(MaxUtil(st, ss, mid, l, r, 2 * node + 1),
               MaxUtil(st, mid + 1, se, l, r, 2 * node + 2));
}
void updateValue(int arr[], int* st, int ss, int se, int index, int value, int node)
{
    if (index < ss || index > se) {
        cout << "Invalid Input" << endl;
        return;
    }
     
    if (ss == se) {  
        arr[index] = value;
        st[node] = value;
    }
    else {
		int mid = getMid(ss, se);
		if (index >= ss && index <= mid)
			updateValue(arr, st, ss, mid, index, value, 2 * node + 1);
		else updateValue(arr, st, mid + 1, se, index, value, 2 * node + 2);
		st[node] = max(st[2 * node + 1], st[2 * node + 2]);
    }
    return;
}
int getMax(int* st, int n, int l, int r)
{
    if (l < 0 || r > n - 1 || l > r) { 
		cout << "Invalid Input" << endl;
		return -1;
	}
    return MaxUtil(st, 0, n - 1, l, r, 0);
}

int constructSTUtil(int arr[], int ss, int se, int* st, int si)
{
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = max(constructSTUtil(arr, ss, mid, st, si * 2 + 1),
                 constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));
    return st[si];
}

int* constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    int* st = new int[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

void Solve()
{
	int n, m; cin>>n>>m;
	int arr[m]; lop(i,m) cin>>arr[i]; 
	int q; cin>>q;
	int* st = constructST(arr, m);

	while(q--){
		int x,y,s,e,k; 
		cin>>x>>s>>y>>e>>k;
		int mx = x + ((n - x) / k) * k;
		if (s > e) swap(s, e);
		int block = getMax(st, m, s - 1, e - 1);
		yes(!(block>=mx or abs(e-s)%k or abs(y-mx)%k)); 
	}
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int Testcase = 1;

	while (Testcase--) Solve();
	return 0;
}

//by stunnerhash