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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void Solve()
{
  int n;
  cin>>n;
  vi a(n );
  loop cin>>a[i];
  int total =0;
  loop total += a[i];
  debug(total);
  if(total%3) {
      cout<<0<<endl;    return;
  }
  // first half 
  int i,temp=0,tp=0;
  for(i =0;i<n and temp != total/3;i++)  temp+=a[i];
    
    if(i == n) {cout<<0<<endl;   return;}

  // second half 
  temp =0; int cnt=0;
  for(;i<n and temp != total/3;i++){
      if(temp == 0) {
          cout<<"flcl\n";
          cnt++;
        }
      temp+=a[i];
  }if(i == n) {
      cout<<"flcl";
      cout<<0<<endl;return;
  }

  // third half
  temp =0; int cntb = 0;
  for(;i<n;i++){
      if(temp ==0) {
        cntb++;
        debug(i,temp);
      }
      temp+= a[i];
  }if(temp!=total/3){
        cout<<0<<endl; return;    
  }
  debug(cnt,cntb);
    cout<< cnt* cntb<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 int Testcase = 1;
 while (Testcase--) Solve();
 return 0;
}