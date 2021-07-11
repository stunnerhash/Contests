#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int LCM(int x, int y) {
	return x / gcd(x, y) * y;
}
void solve() {
	int n;
	cin >> n;
	int G = 1, ans = 0;
	for (int i = 1; G <= n; ++i) {
		G = LCM(G, i);
		if (G > n) break;
		ans += n / G;
	}
	cout << (ans + n) % mod << endl;
}
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int t; cin>>t;
	while (t--) solve();
}