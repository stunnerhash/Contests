#include <bits/stdc++.h>
using namespace std;

#define dbg(x)         {cout<<#x<<"="<<x<<endl;cerr<<#x<<"="<<x<<endl}
#define lp(i, k, n)    for(int i=k;k < n?i < n: i>n;k < n? i+=1: i-=1)
#define yes(flag)      cout<<(flag?"YES":"NO")<<endl;
#define no             {cout << "NO" <<endl; return;}
#define loop           for(int i = 0; i < n; i++)
#define lop(i, n)      for(int i = 0; i < n; i++)
#define clr(x)         memset(x, 0, sizeof( x ) )
#define all(x)         x.begin(),x.end()
#define trav(a)        for (auto it : a)
#define sortall(x)     sort( all ( x ) )
#define ll             long long
#define pb             push_back
#define mp             make_pair
#define INF            (int) 1e9
#define mod            INF + 7
#define ss             second
#define ff             first
#define endl           "\n"
typedef pair<int, int> pi;
typedef pair<ll, ll>   pl;
typedef vector<int>    vi;
typedef vector<ll>     vl;
typedef vector<pi>     vpi;
typedef vector<vi>     vvi;

void __print(int x)            {cerr << x;}
void __print(long x)           {cerr << x;}
void __print(float x)          {cerr << x;}
void __print(double x)         {cerr << x;}
void __print(unsigned x)       {cerr << x;}
void __print(long long x)      {cerr << x;}
void __print(long double x)    {cerr << x;}
void __print(unsigned ll x)    {cerr << x;}
void __print(unsigned long x)  {cerr << x;}
void __print(const char *x)    {cerr << '"' << x << '"';}
void __print(const string &x)  {cerr << '"' << x << '"';}
void __print(char x)           {cerr << '\''<< x <<'\'';}
void __print(bool x)           {cerr <<(x?"true":"false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first);cerr<<',';__print(x.second);cerr<<'}';}
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

const int  N = 1e5+5;

void Solve()
{
	int a,b,c,d; cin>>a>>b>>c>>d;
	int n = 4;
	vi s{a,b,c,d};
	int cnt = 0; loop cnt+=s[i];
	if(cnt == 0) cout<<0<<endl;

	else if(cnt == 4) cout<<2<<endl;
	else cout<<1<<endl;
}

signed main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 

 int Testcase = 1;
 cin>>Testcase;

 while (Testcase--) Solve();
 return 0;
}