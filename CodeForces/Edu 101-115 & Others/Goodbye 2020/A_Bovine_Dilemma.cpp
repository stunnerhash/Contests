#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop for(int i = 0; i < n; i++) 
#define looop(i, n) for (int i = 0; i < n; i++) 
#define loopp(i, k, n) for (int i = k; k < n? i < n: i > n; k < n? i += 1: i -= 1) 
#define dbug(x) cout << #x << "=" << x << endl
#define debug(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
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
{
  int n;
  cin>>n;
  set<int> s;
  int vec[n];
  loop
      cin>>vec[i];
  loop
      loopp(j,i+1,n){
        int num = vec[i]-vec[j];
        // debug(i,j);
        // dbug(num);
        s.insert(num);
      }
    cout<<s.size()<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 

 int Testcase = 1;
 cin >> Testcase;

 while (Testcase--) Solve();
 return 0;
}