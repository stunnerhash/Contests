//incomplete
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
#define mod 1000000007
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
int n;
int recurse(vi a , vi b,vi c,vi d ,int k,int l,int m,vi flag){
    if(l == k){
        int ans =0;
        debug(flag);
        lop(i,m) if(flag[a[i]] && flag [b[i]]) ans++;
        return ans;
    }
    flag [c[l]] =1;
    int temp1 = recurse(a,b,c,d,k,l+1,m,flag);
    flag [c[l]] =0;
    flag [d[l]] =1;
    int temp2= recurse(a,b,c,d,k,l+1,m,flag);
    return max(temp1,temp2);
}

void Solve()
{
    int  m;
    cin>>n>>m;
    vi a(m),b(m);
    lop(i,m) cin>> a[i]>>b[i];
    int k;
    cin>>k;
    vi c(k),d(k);
    lop (i,k) cin>> c[i]>>d[i];
    vi flag (n+1,0);
    flag [c[0]] =1;
    int temp1 = recurse(a,b,c,d,k,1,m,flag);
    flag [c[0]] =0;
    flag [d[0]] =1;
    int temp2= recurse(a,b,c,d,k,1,m,flag);
    cout<< max( temp1,temp2);
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 srand(chrono::high_resolution_clock::now().time_since_epoch().count());

 int Testcase = 1;

 while (Testcase--) Solve();
 return 0;
}