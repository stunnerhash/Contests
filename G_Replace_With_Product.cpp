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

void solve() {
    int n; cin>>n;
    vl a(n+1); loop cin>>a[i+1];
    int prod = 1; loop prod= min(inf,a[i+1]*prod);
    if(prod>=2*n){
        int l = 1,r = n;
        while(a[l] == 1 and l<r) l++;
        while(a[r] == 1 and l<r) r--;
        cout<<l<<' '<<r<<endl;
    }
    vector<int> ind, pre(n+1),suf(n+1),product(n+1);
    product[0] = 1;
    loop {
        if (a[i] > 1) ind.pb(i);
        pre[i + 1] = pre[i] + a[i+1];
        product[i + 1] = product[i] * a[i+1];
    }
    for(int i=n-1; i>= 0; i--) suf[i] = suf[i + 1] + a[i];
    if(ind.size() == 1) {
        cout << ind.front() + 1 << " " << ind.front() + 1 << "\n";
        return ;
    }

    int l = 0,r = 0;
    prod = accumulate(all(a),0LL);
    for(int i = 0; i < ind.size(); i++){
        for(int k = i + 1; k < ind.size(); k++){
            int val = product[ind[k] + 1] / product[ind[i]];
            val += pre[ind[i]];
            val += suf[ind[k] + 1];
            if(val > prod){
                l = ind[i];
                r = ind[k];
                prod = val;
            }
        }
    }
 
    cout << l + 1 << " " << r + 1 << "\n";
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