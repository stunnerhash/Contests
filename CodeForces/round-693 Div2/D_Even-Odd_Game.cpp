//in-complete
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
  int n ;
  cin>>n;
  vector<ll> even ;
  vector<ll> odd;
  loop{
       ll  x;
       cin>>x;
       if(x%2) odd.pb(x);
        else even.pb(x);
  }
  ll suma=0, sumb =0;
  int temp = min(even.size(),odd.size());
    bool flag = (temp == even.size());
    sort(even.begin(),even.end(),greater<int>());
    sort(odd.begin(),odd.end(),greater<int>());
    int i =0,j=0;
    int x =0;
    while(i<even.size() and j<odd.size()){
        //alice turn
        if(even[i] > odd[j]){
            suma+= even[i];
            i++;
        }
        else{
         j++;
        }
        x++;
        //bob turn
        if(j<odd.size() and i<even.size()){
            if(even[i] < odd[j]){
                sumb += odd[j];
                j++;
            }
            else{
                i++;
            } 
            x++;
        }
    }
    if(x%2) i++;
    while(i<even.size()){
        suma+=even[i];
        i+=2;
    }
    if(x%2==0) j++;
    while(j<odd.size()){
        sumb += odd[j];
        j+= 2;
    }
    if(suma== sumb ) cout<<"Tie\n";
    else if (suma>sumb) cout<<"Alice\n";
    else cout<< "Bob\n";
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 srand(chrono::high_resolution_clock::now().time_since_epoch().count());

 int Testcase = 1;
 cin >> Testcase;

 while (Testcase--) Solve();
 return 0;
}