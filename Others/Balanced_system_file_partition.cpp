//incomplete wiith no good solution on web;
#include <bits/stdc++.h>
using namespace std;


int mostBalancedPartition(vector<int> parent, vector<int> size) {
    int n = parent.size(),total = 0;
    sort(parent.begin(),parent.end());
    for(int i =0 ; i < n; i++ ) total+= size[i];
    bool flag[n];
    for(int i =0;i<n;i++) flag[i] =1;
    for(int i =1;i<n;i++) flag[parent[i]] =0;
    int ans = INT_MAX;
    for(int i = n-1; i>0;i--){
        if(flag[i] == 0) continue;
        int temp = 0, idx=i;
        while(1){
            temp += size[idx];
            ans = min(abs(total- 2*temp) ,ans);
            cout<<ans<<endl;
            idx = parent[idx];
            if(idx == -1) break;
        }
    }
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> parent(n),size(n);
    for(int i = 0; i < n; i++) cin>>parent[i];
    for(int i = 0; i < n; i++) cin>>size[i]; 
    cout<<mostBalancedPartition(parent,size)<<endl;
}