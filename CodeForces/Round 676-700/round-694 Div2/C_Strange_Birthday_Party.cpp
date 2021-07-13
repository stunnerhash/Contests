// incomplete
#include <bits/stdc++.h>
using namespace std;

#define lop(i, n) for (int i = 0; i < n; i++)
#define loop 	  for (int i = 0; i < n; i++)
#define all(x) 	  x.begin(), x.end()
#define sortall(x) sort(all(x))
typedef vector<int> vi;

#define int long long 
void Solve()
{
	int n, m;
	cin >> n >> m;
	vi k(n), c(m);
	loop cin >> k[i];
	lop(i, m) cin >> c[i];

	sort(all(k), greater<int>());

	int sum = 0, r = 0;

	loop 
		if(k[i]-1 >= r){
			sum+= c[r];
			r++;
		}
		else while(i<n){
				sum+= c[k[i]-1];
				i++;
		}
	cout << sum << endl;
}

signed main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 srand(chrono::high_resolution_clock::now().time_since_epoch().count());

 int Testcase = 1;
 cin >> Testcase;

 while (Testcase--) Solve();
 return 0;
}