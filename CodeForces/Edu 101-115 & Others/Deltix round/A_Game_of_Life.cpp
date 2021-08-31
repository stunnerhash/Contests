
#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  vector<int>ones;
  for(int i=0;i<n;i++) if(s[i]=='1')ones.push_back(i);
  if(ones.empty()){
    cout<<s<<endl;
    return;
  }
  for(int i=0;i<n;i++){
    int x=upper_bound(ones.begin(),ones.end(),i)-ones.begin();
    if(x==(int)ones.size()){
      int dis=i-ones[x-1];
      if(dis<=m) s[i]='1';
    }
    else if(x){
      int dis1=ones[x]-i;
      int dis2=i-ones[x-1];
      if(dis1==dis2){ }
	   else{
        if(min(dis1,dis2)<=m) s[i]='1';
      }
    }
    else{
      int dis=ones[x]-i;
      if(dis<=m) s[i]='1';
    }
  }
  cout<<s;
  cout<<endl;
}
int main(){
      int t;
      cin>>t;
      while(t--) solve();
      return 0;
}