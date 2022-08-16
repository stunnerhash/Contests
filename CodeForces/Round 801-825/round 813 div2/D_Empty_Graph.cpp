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

// const int N = 2e6;
// int n;
// int a[N],b[N];
 
// bool blackbox(int m,int k){
//     int cnt = 0;
//     for(int i = 1; i <= n; i++){
//         a[i] = b[i];
//         if(2 * a[i] < m){
//             a[i] = inf;
//             cnt++;
//         }
//     }
//     if(cnt > k)
//         return false;
//     k -= cnt;
//     if(k >= 2)
//         return true;
//     for(int i = 1; i + 1 <= n; i++){
//         if(a[i] >= m && a[i+1] >= m)
//             return true;
//     }
//     if(k == 0)
//         return false;
//     for(int i = 1; i <= n; i++){
//         if(a[i] >= m)
//             return true;
//     }
//     return false;
// }
 
// void solve(){
//     int k;
//     cin >> n >> k;
 
//     vector<pair<int,int>> v;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//         b[i] = a[i];
//     }
 
//     int ans = 0;
//     int l = 0, r = inf+1;
//     while(r - l > 1){
//         int m = (l+r)>>1;
//         if(blackbox(m,k)) l = m;
//         else r = m;
//     }
 
//     cout << l << "\n";
//     return;
// }

void solve()
{
	int n; cin>>n;
	int k; cin>>k;
	vl a(n), b(n);
	loop {
		cin >> a[i];
		b[i] = a[i];
	}
	sortall(b);

	map<int,int> m;
	lop(i,k) m[b[i]]++;
	loop if (m[a[i]]) {
		m[a[i]]--;
		a[i] = 1e9;
	}
	int ans = -1;
	lop(i,n-1) ans = max(ans,min(a[i],a[i+1]));
	int mini = *min_element(all(a));
	
	cout<<min(2*mini,ans)<<endl;
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

//I, stunnerhash, hereby declare myself as the owner of this piece of shit code.