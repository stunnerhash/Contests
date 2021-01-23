#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop for(int i = 0; i < n; i++) 
#define lop(i, n) for (int i = 0; i < n; i++) 
#define lp(i, k, n) for (int i = k; k < n? i < n: i > n; k < n? i += 1: i -= 1) 
#define dbg(x) cout << #x << "=" << x << endl
#define dbug(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define clr(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define trav(a) for (auto it = a.begin(); it != a.end(); it++)
#define endl "\n"
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

void Solve()
{ //input
  
  int n;cin>>n;
  vector<ll> a(n+1);
  loop cin>>a[i];

  ll sum=0;
  loop sum += a[i];
  
  if(sum%3) { cout<<0<<endl;  return; }
  
  ll suma =0,sumb =0,s1 =0;

  for(ll i =0; i<n-1; i++){
    s1 +=a[i];
    if(s1 == 2*sum/3) sumb +=suma;
    if(s1 == sum/3) suma++;
  }
   cout<<sumb<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 srand(chrono::high_resolution_clock::now().time_since_epoch().count());

 int Testcase = 1;

 while (Testcase--) Solve();
 return 0;
}