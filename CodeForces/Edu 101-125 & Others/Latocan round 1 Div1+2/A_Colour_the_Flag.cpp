#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop for(int i = 0; i < n; i++) 
#define lop(i, n) for (int i = 0; i < n; i++) 
#define lp(i, k, n) for (int i = k; k < n? i < n: i > n; k < n? i += 1: i -= 1) 
#define dbg(x) cout << #x << "=" << x << endl
#define dbug(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define read(type) readInt<type>()
#define pb push_back
#define mp make_pair
#define clr(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define trav(a) for (auto it = a.begin(); it != a.end(); it++)
#define endl "\n"
#define INF (int)1e9
#define EPS 1e-9
#define mod 1000000007
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

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

void Solve()
{
	int n ,m;
	cin>>n>>m;
	vvi a(n,vi (m,0));
	bool flag = 1;
	loop lop(k,m) {
		char c;
		cin>>c;
		if(c=='R') {a[i][k] = -1; flag = 0;}
		else if(c== 'W') {a[i][k]  =1;flag = 0;}
		else a[i][k] = 0;
	
	}
	if(flag ){
		a[0][0] = 1;
	}
	lop(x,1){
	loop {
		lop(k,m){
			debug(a);
			if(a[i][k] == 1){
				int l = 0,o=0;
				if(i%2 == 1) l = 1;
				if(k%2 == 1) o = 1;
				for(;l<n;l+=2) {
					if(a[l][k] >= 0 )	{
						a[l][k] = 1;
					}
					else {
						cout<<"NO\n";
						return;
					}
				}
				for(;o<m;o+=2){
					if(a[i][o] >= 0){
						a[i][o] = 1;
					}
					else {
						cout<<"NO\n";
						return;
					}
				}
			}
			if(a[i][k] == -1){
				int l = 0,o=0;
				if(i%2 == 1) l = 1;
				if(k%2 == 1) o = 1;
				for(;l<n;l+=2) {
					if(a[l][k] <=0 )	{
						a[l][k] = -1;
					}
					else {
						cout<<"NO\n";
						return;
					}
				}
				for(;o<m;o+=2){
					if(a[i][o] <=0){
						a[i][o] = -1;
					}
					else {
						cout<<"NO\n";
						return;
					}
				}
			}
		}
	}
	}

	loop {
		lop(k,m){
			if(a[i][k] == 0) continue;
			int notbe = a[i][k]; 
			if(i>=1){
				if(a[i-1][k] == notbe) {
					cout<<"NO"<<endl;
					return;
				}
				a[i-1][k] = -(a[i][k]);
			}
			if(k>=1){
				if(a[i][k-1] == notbe) {
					cout<<"NO"<<endl;
					return;
				}
				 a[i][k-1] = -(a[i][k]);
			}
			if(i<=n-2) {
				if(a[i+1][k] == notbe) {
					cout<<"NO"<<endl;
					return;
				}
				a[i+1][k] = -(a[i][k]);
			}
			if(k<=m-2) {
				if(a[i][k+1] == notbe) {
					cout<<"NO"<<endl;
					return;
				}
				a[i][k+1] = -(a[i][k]);
			}
		}
	}

	if(a[0][0] == 0) {
		if(n>=2) {
			a[0][0] = -a[1][0];
		}
		else if(m>=2){
			a[0][0] = -a[0][1];
		}
		else a[0][0] = 1;
	}
	cout<<"YES\n";
	
	loop{
		lop(k,m){
			if(a[i][k] == -1) cout<<"R";
			else if (a[i][k] == 1)cout<<"W";
			else cout<<".";
		}
		cout<<endl;
	}
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 srand(chrono::high_resolution_clock::now().time_since_epoch().count());

 int Testcase = 1;
 cin>>Testcase;   
 while (Testcase--)Solve();
 return 0;
}