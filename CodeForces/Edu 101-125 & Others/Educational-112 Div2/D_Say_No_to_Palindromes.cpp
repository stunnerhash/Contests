#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	string s; cin >> s;

	vector<vector<int>> pr(6, vector<int>(n + 1));
	string t = "abc";
	int cur = 0;
	do {
		for (int i = 0; i < n; ++i)
			pr[cur][i + 1] = pr[cur][i] + (s[i] != t[i % 3]);
		++cur;
	} while (next_permutation(t.begin(), t.end()));

	while (m--)
	{
		int l, r;
		cin >> l >> r;
		int ans = n;
		for (int i = 0; i < 6; ++i)
			ans = min(ans, pr[i][r] - pr[i][l - 1]);
		cout << ans <<endl; 
	}
}

int main() {
	solve();
}