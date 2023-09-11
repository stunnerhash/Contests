#include <bits/stdc++.h>
using namespace std;

#define loop           	for (int i = 0; i < n; i++)
#define all(x)         	x.begin(), x.end()
#define sortall(x)      sort(all(x))

#define int long long

void solve() {
    int n; cin>>n;
    vector<int> a(n); loop cin>>a[i];
    sortall(a);
    int mex = 0,val = -1,flag = 0;
    for (int i = 0; i <= n; i++) {
        if(i == n or a[i]!= i+flag){
            mex = i;
            if (flag) break;
            if(val == -1) val = i;
            flag = 1; 
        }
    }
    if(a.back() == mex) mex++;
    cout<<val<<' ';
    while (true){
        int in; cin>>in;
        if(in == -1) break;
        else cout<<in<<' ';
    }
}

signed main()
{

	int tc = 1;
	cin>>tc;

	while (tc--) solve();
	return 0;
}
// If it works... don't touch it.