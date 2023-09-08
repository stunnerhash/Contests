#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop for(int i = 0; i < n; i++) 

#define int ll 

void Solve()
{
  int x,n ;
  cin>>n>>x;
  int a[n]; loop cin>>a[i];
  int temp=0,sum =0;
  
  loop{
     temp += ceil((long double)a[i]/x);
     sum += a[i];
  }
  int mini = ceil((long double)sum/x);
    cout<< mini<<" "<<temp<<endl;
}

signed main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 

 int Testcase = 1;
 cin >> Testcase;

 while (Testcase--) Solve();
 return 0;
}