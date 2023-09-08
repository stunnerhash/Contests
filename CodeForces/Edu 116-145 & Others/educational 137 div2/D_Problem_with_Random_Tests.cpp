#include <bits/stdc++.h>
using namespace std;

#define loop           	for (int i = 0; i < n; i++)
#define all(x)         	x.begin(), x.end()
#define sortall(x)    	sort(all(x))
#define pb             	push_back
#define endl           	"\n"
typedef vector<int>    	vi;

#define int long long

void solve()
{
	int n; cin>>n;
	string s; cin>>s; reverse(all(s));
	while(s.back() == '0') s.pop_back();
	reverse(all(s));
	if(s.size() == 0){
		cout<<0<<endl;
		return;
	}
	set<int>z,o;
	loop s[i] == '0'?z.insert(i):o.insert(i);
	
	int ans = 0;
	for(int i = 1;i<n;i++){
		int cnt = 0;
		for(auto it:z){
			if(it-i<0 or o.find(it-i) == o.end()) break;
			cnt++;
		}
		if(cnt>ans) ans = cnt;
	}
	vector<int> cand;
	for(int i = 1;i<n;i++){
		int cnt = 0;
		for(auto it:z){
			if(it-i<0 or o.find(it-i) == o.end()) break;
			cnt++;
		}
		if(cnt==ans)
			cand.pb(i);	
	}
	

	int shift = 0;
	vi best;
	for(auto t:cand){
		vi arr;
		for(auto it:z){
			if(o.find(it-t)!= o.end()) arr.pb(it);
		}
		bool ok = 0;
		for(int i = 0;i<max(best.size(),arr.size());i++){
			if(i>=best.size() or arr[i] <best[i]){
				ok = 1;
				break;
			}
			else if(arr[i]>best[i]) break;
		}
		if(ok){
			best = arr; 
			shift = t;
		}
	}
	for(auto i:best) s[i] = '1';
	cout<<s<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
 
	int tc = 1;
	while (tc--)
		solve();
}

//I, stunnerhash, hereby declare myself as the owner of this piece of shit code.