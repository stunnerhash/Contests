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
int getmin(int n){
	string s = to_string(n);
	sortall(s);
	return s.front()-'0';
}
int getmin(string s){
	sortall(s);
	return s.front()-'0';
}
int getmax(int n){
	string s = to_string(n);
	sortall(s);
	return s.back()-'0';
}
int getmax(string s){
	sortall(s);
	return s.back()-'0';
}

void solve() {
	int l, r; cin >> l >> r;
	if(l<10) returnn(l);
	string ls = to_string(l), rs = to_string(r);
	while(ls.size()<rs.size()) ls = '0'+ls;
	if(rs.front()-ls.front()>1){
		int ch = ls.front()-'0'+1;
		string temp;
		for(int i = 0; i<ls.size();i++)  temp += to_string(ch);
		returnn(temp);
	} 
	string cng= to_string(r-l);

	int mi = 9, mx = 0;
	int pivot = ls.size()-cng.size();
	if(pivot>0 and ls[pivot-1] != rs[pivot-1]) pivot--;
	for(int i = 0;i<pivot;i++){
		mi = min((int)ls[i]-'0',mi);	
		mx = max((int)ls[i]-'0',mx);
	}
	int ls_mx = 0,rs_mi = 9; 
	for(int i = pivot+1; i<ls.size();i++){
		ls_mx = max(ls_mx,(int)ls[i]-'0');
		rs_mi = min(rs_mi,(int)rs[i]-'0');
	}
	int left = ls[pivot]-'0';
	int right = rs[pivot]-'0';
	int res = 10;
	string ans;
	for (int i = left + 1;  i < right; i++) {
		string s =  to_string(i);
		if(pivot != 0) s += to_string(mi)+ to_string(mx);
		if (res >= getmax(s) - getmin(s)){
			res = getmax(s) - getmin(s);
			string temp;
			for(int k = 0;k<pivot;k++)  temp+= ls[k];
			for(int k = pivot;k<ls.size();k++) temp += to_string(i);
			ans = temp;
		}
	}
	for(int i = ls_mx;i<=9;i++){
		string s = to_string(left) + to_string(i);
		if(pivot != 0)  s += to_string(mi)+ to_string(mx);
		string temp;
		if (res >= getmax(s) - getmin(s)){
			res = getmax(s) - getmin(s);
			for(int k = 0;k<pivot;k++)  temp+= ls[k];
			temp += to_string(left);
			for(int k = pivot+1;k<ls.size();k++) temp += to_string(i);
			ans = temp;
		}
	}
	for(int i = rs_mi;i>=0;i--){
		string s = to_string(right) + to_string(i);
		if(pivot != 0)  s += to_string(mi)+ to_string(mx);
		string temp;
		if (res >= getmax(s) - getmin(s)){
			res = getmax(s) - getmin(s);
			for(int k = 0;k<pivot;k++)  temp+= ls[k];
			temp += to_string(right);
			for(int k = pivot+1;k<ls.size();k++) temp += to_string(i);
			ans = temp;
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