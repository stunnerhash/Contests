#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
	for(int i=2;; i++){
		int r = i;
		int a, b ;
		cout << "? 1 "<< r << endl;
		cin >> a;
		cout << "? " << r << " " << 1 << endl;
		cin >> b;
		if(a!=b){
			cout << "! " << a+b << endl;
			return 0;
		}
		if(a==-1){
			cout << "! " << i-1 << endl;
			return 0;
		}
	}
}

//I, stunnerhash, hereby declare myself as the owner of this piece of shit code.