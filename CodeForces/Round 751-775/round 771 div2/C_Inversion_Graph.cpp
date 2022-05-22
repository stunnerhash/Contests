#include <bits/stdc++.h>
using namespace std;


int main()
{
	int t = 1;cin>>t;

	while (t--){

		int n; cin>>n;
		vector<int> a(n); 

		for(int i = 0;i<n;i++) cin>>a[i];
		stack<int> s;

		s.push(a[0]);

		for (int i = 1; i < n; i++)
		{
			int max = s.top();
			if (a[i] > max) {
				s.push(a[i]);
				continue;
			}
			while (!s.empty() and s.top() > a[i])
				s.pop();	

			s.push(max);
		}

		cout<<s.size()<<endl;
	}
	return 0;
}