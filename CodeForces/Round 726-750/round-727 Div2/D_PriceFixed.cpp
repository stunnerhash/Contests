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
#define mod 1e9+7
#define int ll
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

void Solve(){
	int n;
	cin >> n;
	vector<pi> p(n);
	loop cin >> p[i].second>> p[i].first;
	sort(all(p));
	int s = 0, e = n - 1;
	int ans = 0;
	int bought = 0;
	while(s <= e){
		if(p[s].first <= bought){
			bought += p[s].second;
			ans += p[s].second;
			s++;
		}
		else{
			int req = min(p[s].first - bought, p[e].second	);
			bought += req;
			p[e].second -= req;
			ans += 2 * req;
			if(p[e].second == 0)e--;
		}
	}
	cout << ans;
}

signed main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
 int Testcase = 1;
 while (Testcase--)Solve();
 return 0;
}
