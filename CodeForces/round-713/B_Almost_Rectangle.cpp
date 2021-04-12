#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop for(int i = 0; i < n; i++) 
#define lop(i, n) for (int i = 0; i < n; i++) 
#define lp(i, k, n) for (int i = k; k < n? i < n: i > n; k < n? i += 1: i -= 1) 
#define dbg(x) cout << #x << "=" << x << endl
#define dbug(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define read(type) readInt<type>()
#define pb push_back
#define mp make_pair
#define clr(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define trav(a) for (auto it = a.begin(); it != a.end(); it++)
#define endl "\n"
#define INF (int)1e9
#define EPS 1e-9
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

void Solve()
{
    int n;
    cin>>n;
    int a[n][n];
    vpi cor;
    loop{
        for(int j=0;j<n;j++) {
            char c;
            cin>>c;
            if(c == '*') {
                cor.pb(mp(i,j));
                a[i][j] = 1;
            }
            else a[i][j] = 0;
        }
    }
    vpi newcor;
    if(cor[0].first != cor[1].first && cor[0].second != cor[1].second){
        newcor.pb(mp(cor[0].first,cor[1].second));
        newcor.pb(mp(cor[1].first,cor[0].second)); 
    }
    else if(cor[0].first == cor[1].first){
        if (cor[0].first == 0){
            newcor.pb(mp(cor[0].first+1,cor[0].second));
            newcor.pb(mp(cor[1].first+1, cor[1].second));
        }
        else {
            newcor.pb(mp(cor[0].first-1,cor[0].second));
            newcor.pb(mp(cor[1].first-1, cor[1].second));
        }
    }
    else {
        if(cor[0].second == 0){
            newcor.pb(mp(cor[0].first,cor[0].second+1));
            newcor.pb(mp(cor[1].first, cor[1].second+1));
        }
        else {
            newcor.pb(mp(cor[0].first,cor[0].second-1));
            newcor.pb(mp(cor[1].first, cor[1].second-1));
        }
    }
    a[newcor[0].first][newcor[0].second] =1;
    a[newcor[1].first][newcor[1].second] = 1;
    debug(cor);
    debug(newcor);
    loop{
        for(int j=0;j<n;j++) {
            if(a[i][j] == 1) cout<<'*';
            else cout<<'.';
        }
        cout<<endl;
    }
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 srand(chrono::high_resolution_clock::now().time_since_epoch().count());

 int Testcase = 1;
 cin>>Testcase;   
 while (Testcase--)Solve();
 return 0;
}