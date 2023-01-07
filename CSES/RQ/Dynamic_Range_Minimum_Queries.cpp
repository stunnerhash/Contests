#include <bits/stdc++.h>
using namespace std;

#define int long long
#define loop for (int i = 0; i < n; i++)

const int N = 3e5;
int a[N], seg[4*N];// 
int n,q;
// update 
void update(int id, int val, int node = 0, int left = 0, int right = n-1){
	if(id>right or id<left) return;// return; 
	if(left == right and left == id){
		seg[node] = val;
		return;
	}
	int mid = (left+right)/2;
	update(id, val, node*2+1, left, mid );//leftchild node = node*2 +1
	update(id, val, node*2+2, mid+1,right);//right child 
	seg[node] = min(seg[node*2+1],seg[node*2+2]);
}
// query 
int query(int ql, int qr,int node = 0, int left = 0, int right = n-1){
	if(left>=ql and right<=qr) return seg[node];
	if(left>qr or right<ql) return INT_MAX;

	// partial part 
	int mid = (left+right)/2;
	return min(query(ql, qr, node * 2 + 1, left, mid) 
		 , query(ql, qr, node * 2 + 2, mid + 1, right));
}


signed main() {
	cin>>n>>q;
	loop cin>>a[i];
	loop update(i,a[i]); // build the segmentree;
	while(q--){
		int type; cin>>type;
		if(type == 1){
			int id, val; cin>>id>>val; id--;
			update(id,val);
		}
		else{
			int ql, qr; cin>>ql>>qr; ql--,qr--;
			cout<<query(ql,qr)<<endl;
		}
	}
}