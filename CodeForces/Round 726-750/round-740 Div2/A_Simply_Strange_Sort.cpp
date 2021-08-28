#include <bits/stdc++.h>
using namespace std;

#define loop for(int i =0;i<n;i++)
typedef vector<int> vi;

bool sorted(vi a) {
	int n = a.size();
    for(int i = 0; i < n; i++)
        if(a[i] != i+1)
            return false;
    return true;
}

void solve() {
	int n, flag = 0, cnt = 0; cin >> n;
	vi a(n); loop cin>>a[i];


	while(!sorted(a)) {
			if(flag%2 == 0) {
			for(int j = 0; j < n-1; j = j+2)
				if(a[j] > a[j+1]) swap(a[j], a[j+1]);
		}
		else {
			for(int j = 1; j < n; j = j+2)
				if(a[j] > a[j+1]) swap(a[j], a[j+1]);
		}
		flag++,cnt++;
	}
	cout<<cnt<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)solve();
}
