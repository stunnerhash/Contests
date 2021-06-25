//incomplete , the valley of 2 have issues , it does not boils to 0 when valley has consecutive hilss and valleys 
// think to eleminate that possibility where the example abcde

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

int valley (ll a[],int n){
    int ans =0;
    for(int i =1;i<n-1;i++)
        if( (a[i]>a[i-1] and a[i]> a[i+1]) or (a[i] < a[i-1] and a[i] < a[i+1]))
        ans ++;
    return ans;
}
bool is_valley(ll a[],int i){
    if((a[i]<a[i-1]) && (a[i]< a[i+1]))
     return 1;
    return 0;
}
bool is_hill(ll a[], int i){
    if ((a[i] > a[i-1]) && (a[i] > a[i+1]))
        return 1;
    return 0;
}
void Solve()
{
    int n;
    cin>>n;
    ll a[n];
    loop cin>>a[i];
    if(n<=3) {
        cout<< 0<< endl;
        return; 
    }
    int ans = valley(a,n);
    if(ans <= 1){
        cout<< 0<<endl;
        return ;
    }
    int sub;
    if(n>=5){
        for(int i=2;i<n-2;i++){
            if( (is_valley(a,i) and is_hill(a,i-1) and is_hill(a,i+1))) 
            {
                sub =3;
                break;
            }
            else if (is_hill (a,i) and is_valley(a,i-1) and is_valley(a,i+1)){
                sub =3;
                break;
            }
        }
        if(sub ==3) {
            cout<< ans -3<<endl;
            return;
        }
    }

    for(int i=2;i<n-1;i++){
        if ( ( is_valley(a,i-1) and is_hill(a,i)) or( is_valley(a,i) and is_hill(a,i-1))){
            sub =2;
            break;
        }
    }
    if(sub == 2) {
        cout<<ans -2<<endl;
        return;
    }
    cout<< ans-1<<endl;
    return;
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