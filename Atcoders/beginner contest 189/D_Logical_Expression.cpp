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

bool ar[62];
ll recurse(bool ar[],int n)
{
    if (n == 0) {
        if(ar[n]) return 3 ;
        else return 1;   
    }  
    if(ar[n]){
        ll x =pow(2LL,n+1);
        return recurse(ar, n-1) +x;
    }
    else
     return recurse(ar, n-1);
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  
  int n;cin>>n;
  ll ans =0;
  loop {
    string s; cin>>s;

    if(s == "OR"){
        ans += pow(2,i+1);
        ar[i] =1;
    }
    else ar[i] =0;
  }
  cout<<recurse(ar,n-1)<<endl;
 return 0;
}