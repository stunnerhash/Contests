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


void Solve()
{
	int n, k; cin>>n>>k;
	string s; cin>>s;

	if(n%k) {
		cout<<-1<<endl;
		return;
	} 
	vi cnt(26); loop cnt[s[i]-'a']++;

	bool flag = 1;
	lop(i,26) if(cnt[i]%k) flag = 0;
	if (flag) { 
		cout << s << endl;
		return;
	}

	bool found=0;
	int save, i, left;
	for (i = n - 1; i >= 0; i--)
	{
		int rem;
		for (int j = s[i] - 'a' + 1; j < 26; j++)
		{
			int place = 0;
			for (int K = 0; K < 26; K++)
			{
				if (s[i] - 'a' == K) rem = cnt[K] - 1;
				else if (j == K) rem = cnt[K] + 1;
				else rem = cnt[K];

				rem = (k - (rem % k)) % k;
				place += rem;
			}

			if (place <= n - i - 1){
				left = ((n - i - 1) - place);
				if (left % k == 0){
					found = true;
					save = j;
					break;
				}
			}
		}
		if (found) break;
		cnt[s[i] - 'a']--;
	}

	string ans = "";
	fill(all(cnt), 0);

	for (int j = 0; j < i; j++) {
		ans += s[j];
		cnt[s[j] - 'a']++;
	}

	ans += ((char)(save + 'a'));
	cnt[save]++;

	while (left--) 	ans += 'a';
	
	for (int j = 0; j < 26; j++) {
		while (cnt[j] % k != 0) {
			cnt[j]++;
			ans += (char)(j + 'a');
		}
	}
	cout << ans << endl;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int Testcase = 1;
	cin>>Testcase;

	while (Testcase--) Solve();
	return 0;
}