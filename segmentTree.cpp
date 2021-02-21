#include<bits/stdc++.h>
using namespace std;

int a[100005],seg[4*100005];
void segmentTree(int idx , int low , int high){
    if(low == high ) {
        seg[idx] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    segmentTree(2 * idx + 1, low, mid);
    segmentTree(2 * idx + 2, mid + 1, high);
    //segment tree command
    seg[idx] = max( seg[2 * idx + 1], seg[2 * idx + 2]);
}
int query(int idx, int low , int high,int l , int r){
    if (low >= l && high <= r)
        return seg[idx];
    if(high < l || low > r)  return INT_MIN; 
    int mid = (low + high) / 2;
    int left = query(2 * idx + 1, low, mid,l,r);
    int right = query(2 * idx + 2, mid + 1, high,l,r);
    return max(left , right);
}
int main (){
    int n ;
    cin>>n;
    for(int i = 0;i<n;i++) cin>>a[i];
    segmentTree(0,0,n-1);
    for(int i = 0;i<n;i++) cout<<seg[i]<<" " ;
    int q, l,r;
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r)<<endl;
    }
}