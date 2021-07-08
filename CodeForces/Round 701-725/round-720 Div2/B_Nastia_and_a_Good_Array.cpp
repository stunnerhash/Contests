#include "bits/stdc++.h"
using namespace std;

#define loop for(int i =0;i<n;i++)
void solve(){
	int n; cin >> n;
	int x = 1e9 + 7, pos = -1;
	loop {
		int a; cin >> a;
		if (a < x) x = a, pos = i;
	}
	cout << n - 1 << endl;
	loop if (i != pos) cout<<pos+1<<' '<<i+1<<' '<<x<<' '<<x+abs(i-pos)<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int q;
    cin >> q;
    while (q--) solve();

}