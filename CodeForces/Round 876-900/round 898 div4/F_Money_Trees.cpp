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
int maxLen(vector<int>& a, int k) {
    int maxLength = 0,sum = 0, left = 0;
    for (int right = 0; right < a.size(); ++right) {
        sum += a[right];
        while (sum >= k) {
            sum -= a[left];
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}
void solve() {
    int n,k; cin>>n>>k;
	vector<int> a(n), h(n), f(n); 
	loop cin >> a[i]; loop cin >> h[i];
	lop(i,n-1) if(h[i]%h[i+1] == 0) f[i] = 1;
	int ans = 0;
	loop{
		if(f[i]){
			vector<int> temp,temp2;
			while(i<n){
				temp.pb(a[i]); temp2.pb(h[i]);
				if(f[i] == 0) break;
				i++;
			}
			debug(temp2);
			ans = max(ans,maxLen(temp,k));
		}
	}
	cout<<ans<<endl;
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