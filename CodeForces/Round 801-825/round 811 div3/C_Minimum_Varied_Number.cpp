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

void subsetsUtil(vector<int>& A, vector<vector<int> >& res, vector<int>& subset, int index)
{
	res.push_back(subset);
	// Loop to choose from different elements present
	// after the current index 'index'
	for (int i = index; i < A.size(); i++) {

		// include the A[i] in subset.
		subset.push_back(A[i]);

		// move onto the next element.
		subsetsUtil(A, res, subset, i + 1);

		// exclude the A[i] from subset and triggers
		// backtracking.
		subset.pop_back();
	}

	return;
}

vector<vector<int> > subsets(vector<int>& A)
{
	vector<int> subset;
	vector<vector<int> > res;

	int index = 0;
	subsetsUtil(A, res, subset, index);

	return res;
}
// Driver Code.
void Solve()
{
	// find the subsets of below vector.
	vector<int> array = { 0,1, 2, 3,4,5,6,7,8,9 };

	vector<vector<int> > res = subsets(array);
	vl ans(100,1e18);
	for (int i = 0; i < res.size(); i++) {
		int temp = 0;
		int x = 0;
		for (int k = 0; k < res[i].size(); k++){
			x *=10;
			x += res[i][k];
			temp += res[i][k];
		}
		ans[temp] = min(ans[temp],x);
	}
	debug(ans);
	
	int n; cin>>n;
	cout<<aans[n]<<endl;
}


signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int Testcase = 1;
	cin>>Testcase;

	while (Testcase--) Solve();
	return 0;
}

//by stunnerhash