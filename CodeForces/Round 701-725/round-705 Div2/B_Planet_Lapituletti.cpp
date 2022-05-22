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
#define INF            	(int) 1e9
#define mod            	1000000007	
#define ss             	second
#define ff             	first
#define endl           	"\n"
typedef pair<int, int> 	pi;
typedef pair<ll, ll>   	pl;
typedef vector<int>    	vi;
typedef vector<ll>     	vl;
typedef vector<pi>     	vpi;
typedef vector<vi>     	vvi;


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

vi go = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
int inf = 1e9 + 7;

int get(int x) {
    string s = to_string(x);
    if ((int)s.size() == 1) s = "0" + s;
    string ans = "";
    for (int i = 1; i >= 0; --i) {
        if (go[s[i] - '0'] == -1) return INF;
        ans += char(go[s[i] - '0'] + '0');
    }
    return stoi(ans);
}

string good(int x) {
    string ans = to_string(x);
    if (x < 10) ans = "0" + ans;
    return ans;
}

void solve(){
    int h, m; cin >> h >> m;
	string s; cin >> s;
	int H = (s[0] - '0') * 10 + s[1] - '0';
	int M = (s[3] - '0') * 10 + s[4] - '0';

	while (1) {
		if (M == m) H++, M = 0;
		if (H == h) H = 0;

		if (get(M) < h && get(H) < m) {
			cout << good(H) << ":" << good(M) << '\n';
			break;
		}
		M++;
	}
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
    while (t--)solve(); 
}