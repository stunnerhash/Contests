#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop for(int i = 0; i < n; i++) 
#define lop(i, n) for (int i = 0; i < n; i++) 
#define lp(i, k, n) for (int i = k; k < n? i < n: i > n; k < n? i += 1: i -= 1) 
#define trav(a) for (auto it = a.begin(); it != a.end(); it++)
#define yes(flag) cout<<(flag ?"YES":"NO")<<endl;
#define no { cout<<"NO"<<endl; return;}
#define clr(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define endl "\n"
#define mod 1e9+7
#define EPS 1e-9
#define F first
#define S second
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

// #define read(type) readInt<type>()
ll read(){
	char ch=getchar(); ll x=0,f=1;
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch = getchar();}
	while(ch>='0'&&ch<='9') x = x*10 + (ch^48), ch = getchar();
	return x*f;
}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int dp[100004];
int n;
int a[100004];
int func(int ind) {
    if (ind > n) return 0;
 
    if (dp[ind] != -1) return dp[ind];
 
    int count = 0;
 
    for (int i = ind; i <= n; i += ind) {
        if (a[i] > a[ind])
            count = max(count, 1 + func(i));
    }
 
    return dp[ind] = count;
}
 
void Solve()
{

	cin >> n;
	lp(i,1,n+1){
		cin >> a[i];
		dp[i] = -1;
	}

	int maxi = 1;
	lp(i,1,n+1){
		maxi = max(maxi, 1 + func(i));
	}
	cout<<maxi<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 srand(chrono::high_resolution_clock::now().time_since_epoch().count());

 int TestCase=1;
 cin>>TestCase;

 while (TestCase--) Solve();
 return 0;
}