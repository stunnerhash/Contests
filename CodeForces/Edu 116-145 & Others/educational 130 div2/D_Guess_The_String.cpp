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

int countDistinct(int l, int r, string s){
    set<char> st;
    for(int i=l ; i<=r ; ++i)
        st.insert(s[i]);
    return st.size();
}
char one(int x){
	cout<<'?'<<" 1 "<<x+1<<endl;
	char ans; cin>>ans;
	return ans;
}
int two(int x, int y ){
	cout<<'?'<<" 2 "<<x+1<<' '<<y+1<<endl;
	int ans; cin>>ans;
	return ans;
}
void Solve()
{
	int n;cin>>n;	
	string ans(n,'.');
	bool found = 0;
	map<char,int> mp;	
	lop(i,26) mp[i+'a'] = -1;
	ans[0] = one(0);
	mp[ans[0]] = 0;

	int prev = 1;
	for(int i = 1;i<n;i++){
		int cur = two(0,i);
		if(cur != countDistinct(0,i-1,ans)) {
			ans[i] = one(i);
			mp[ans[i]] = i;
			continue;
		}
		vector<pair<int,char>> a;
		for(auto&i :mp) if(i.ss!=-1)a.pb({i.ss,i.ff});
		int low = 0, high = a.size();
		while(low<high){
			int mid = (low+high)/2;
			if(two(a[mid].first,i) == countDistinct(a[mid].first,i-1,ans)){
				ans[i] = a[mid].second;
				low = mid+1;
			}
			else high = mid-1;
		}
		mp[ans[i]] = i;
	}
	debug(ans,mp);
	cout<<"! "<<ans<<endl;
	cout.flush();
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int Testcase = 1;
	Solve();
	return 0;
}

//by stunnerhash