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
int n, m;
vvi a(1002,vi (1002));
vector<string> s;
bool check(int x, int y){
	return (x>=0 and x<n and y>=0 and y<m and s[x][y] == '.');
}


void Solve()
{
	cin>>n>>m;
	s.resize(n); loop cin>>s[i];
	pi start, end;
	loop lop(k,m){
		if(s[i][k]== 'A') start = {i,k};
		if(s[i][k] == 'B') end = {i,k};
	}
	s[end.ff][end.ss] = '.';
	
	queue<pi> q;
	q.push(start);

	bool found = 0;
	while (!q.empty() and !found)
	{
		int i = q.front().ff;
		int k = q.front().ss;
		q.pop();
		if(check(i+1,k)){
			q.push({i+1,k});
			s[i+1][k] = 'D';
			if(i+1 == end.ff and k == end.ss) found = 1;
		}
		if(check(i-1,k)){
			q.push({i-1,k});
			s[i-1][k] = 'U';
			if(i-1 == end.ff and k == end.ss) found = 1;
		}
		if(check(i,k+1)){
			q.push({i,k+1});
			s[i][k+1] = 'R';
			if(i == end.ff and k+1 == end.ss) found = 1;
		}
		if(check(i,k-1)){
			q.push({i,k-1});
			s[i][k-1] = 'L';
			if(i == end.ff and k-1 == end.ss) found = 1;
		}
	}
	int i = end.ff, k = end.ss;
	if(!found) no
	string ans = "";
	while(!(i==start.ff&&k==start.ss)){
		ans += s[i][k];
		switch(s[i][k]){
			case 'D': i--; break;
			case 'U': i++; break;
			case 'R': k--; break;
			case 'L': k++; break;
		}
	}
	reverse(all(ans));
	yes(1); cout<<ans.size()<<endl<<ans<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int Testcase = 1;

	while (Testcase--) Solve();
	return 0;
}

//by stunnerhash